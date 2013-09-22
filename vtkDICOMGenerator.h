/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2013 David Gobbi
  All rights reserved.
  See Copyright.txt or http://www.cognitive-antics.net/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __vtkDICOMGenerator_h
#define __vtkDICOMGenerator_h

#include <vtkObject.h>
#include "vtkDICOMModule.h"
#include "vtkDICOMTag.h"

class vtkIntArray;
class vtkMatrix4x4;
class vtkInformation;
class vtkDICOMMetaData;
class vtkDICOMItem;

//! Generate DICOM data series for specific IOD classes.
/*!
 *  Every DICOM data set must conform to a specific class, where the
 *  properties of all the classes are defined in the DICOM standard.
 *  There are specific IOD classes for MR, CT, ultrasound X-ray, etc., in
 *  fact there are several dozen classes in total.  IOD is the acronym
 *  for Information Object Description, and refers to the attributes that
 *  a data set belonging to a particular IOD class can or must have.  The
 *  vtkDICOMGenerator is an abstract base class that provides support
 *  for most of the common modules in the DICOM standard (i.e. modules
 *  that are shared between modalities).  Subclasses of vtkDICOMGenerator
 *  are concrete classes that provide generation of data sets belonging
 *  to specific modalities.
 */
class VTK_DICOM_EXPORT vtkDICOMGenerator : public vtkObject
{
public:
  //! Static method for construction.
  vtkTypeMacro(vtkDICOMGenerator, vtkObject);

  //! Print information about this object.
  virtual void PrintSelf(ostream& os, vtkIndent indent);

  //! Generate an instance of one of the supported classes.
  /*!
   *  This is the primary interface method of this class.  Given the
   *  information for a vtkImageData object, it will populate the
   *  attributes of the supplied vtkDICOMMetaData object.
   */
  virtual bool GenerateInstance(
    vtkInformation *, vtkDICOMMetaData *) = 0;

  //! Create a multi-frame object (default: Off).
  /*!
   *  If this is on, the one multi-frame data set will be created.  If
   *  this is off, then each slice will be put into a different data set.
   *  The latter is more likely to be compatible with older software.
   */
  vtkSetMacro(MultiFrame, int);
  vtkBooleanMacro(MultiFrame, int);
  vtkGetMacro(MultiFrame, int);

  //! Write scalar components as the time dimension (default: Off).
  /*!
   *  If this is on, then each time slot is stored in a different scalar
   *  component of the image data.  If it is off, then each block of N
   *  adjacent slices correspond to the N time slots of the time dimension.
   */
  vtkSetMacro(TimeAsVector, int);
  vtkBooleanMacro(TimeAsVector, int);
  vtkGetMacro(TimeAsVector, int);

  //! Set the time dimension to use in the DICOM file (or zero if none).
  /*!
   *  The number of components of the input data must be divisible by the
   *  time dimension if the time dimension is not set to zero.  The vector
   *  dimension will be set to the number of components divided by the time
   *  dimension.  This will be ignored if the SOP Class IOD does not permit
   *  a time dimension.
   */
  vtkSetMacro(TimeDimension, int);
  vtkGetMacro(TimeDimension, int);
  vtkSetMacro(TimeSpacing, double);
  vtkGetMacro(TimeSpacing, double);

  //! Set the matrix that places the image in DICOM patient coords.
  /*!
   *  The 3x3 portion of the matrix must be orthonormal, and the
   *  last column of the matrix is understood to be in millimetres.
   */
  void SetPatientMatrix(vtkMatrix4x4 *);
  vtkMatrix4x4 *GetPatientMatrix() { return this->PatientMatrix; }

  //! Let the generator know how the image is arranged in memory.
  /*!
   *  The generator needs to know how to interpret the geometry of
   *  the image that is described in the vtkInformation object that
   *  accompanies the image.  For example, VTK display coordinates
   *  place the Origin at the lower left corner of the screen, while
   *  DICOM assumes that images will be displayed with the "origin"
   *  at the top left corner.  By default, OriginAtBottom is On.
   */
  vtkSetMacro(OriginAtBottom, int);
  vtkGetMacro(OriginAtBottom, int);

  //! Set some meta data for the constructor to use as a hint.
  /*!
   *  The supplied meta data can provide some general properties
   *  of the data set, such as the patient information and study
   *  information.  Only portions of the meta data that are permitted
   *  by the generated IOD will be included.
   */
  void SetMetaData(vtkDICOMMetaData *);
  vtkDICOMMetaData *GetMetaData();

  //! Get an array that maps file and frame to slice.
  /*!
   *  Once the generator has created the metadata, this array lets the
   *  writer know which slice to write out as which frame in which file.
   *  This will be a 2D array, with the file as the first index and the
   *  frame as the second index.
   */
  vtkIntArray *GetSliceIndexArray() { return this->SliceIndexArray; }

protected:
  vtkDICOMGenerator();
  ~vtkDICOMGenerator();

  //! Generate the DICOM SOP Common Module.
  virtual bool GenerateSOPCommonModule(
    vtkDICOMMetaData *meta, const char *SOPClass);

  //! Generate the DICOM Patient Module.
  virtual bool GeneratePatientModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Clinical Trial Subject Module.
  virtual bool GenerateClinicalTrialSubjectModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM General Study Module.
  virtual bool GenerateGeneralStudyModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Patient Study Module.
  virtual bool GeneratePatientStudyModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Clinical Trial Study Module.
  virtual bool GenerateClinicalTrialStudyModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Series Module.
  virtual bool GenerateGeneralSeriesModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Clinical Trial Series Module.
  virtual bool GenerateClinicalTrialSeriesModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Equipment Module.
  virtual bool GenerateGeneralEquipmentModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Image Module.
  virtual bool GenerateGeneralImageModule(vtkDICOMMetaData *meta);

  //! Generate the DICOM Plane Module.
  virtual bool GenerateImagePlaneModule(
    vtkDICOMMetaData *meta, vtkInformation *info);

  //! Generate the DICOM Pixel Module.
  virtual bool GenerateImagePixelModule(
    vtkDICOMMetaData *meta, vtkInformation *info);

  //! Generate The DICOM Multi-frame Module.
  virtual bool GenerateMultiFrameModule(
    vtkDICOMMetaData *meta, vtkInformation *info);

  //! Generate The DICOM Device Module.
  virtual bool GenerateDeviceModule(vtkDICOMMetaData *meta);

  //! Generate The DICOM Specimen Module.
  virtual bool GenerateSpecimenModule(vtkDICOMMetaData *meta);

  //! Copy required attributes into the meta data.
  /*!
   *  Required attributes must be set, so if no value is available,
   *  then an empty zero-length attribute will be created for them.
   *  The list of tags must be terminated with DC::ItemDelimitationItem.
   */
  virtual bool CopyRequiredAttributes(
    const DC::EnumType *tags, vtkDICOMMetaData *meta);

  //! Copy optional attributes into the meta data.
  /*!
   *  The list of tags must be terminated with DC::ItemDelimitationItem.
   */
  virtual bool CopyOptionalAttributes(
    const DC::EnumType *tags, vtkDICOMMetaData *meta);

  //! Compute aspect ratio from spacing.
  static void ComputeAspectRatio(const double spacing[2], int aspect[2]);

  //! Compute the matrix, needed for Position and Orientation.
  void ComputeAdjustedMatrix(
    vtkInformation *info, double matrix[16],
    double origin[3], double spacing[3]);

  //! Compute the position and orientation for a slice.
  /*!
   *  Given the origin of a slice (the position of the corner of the slice
   *  in VTK data coordinates), and a 4x4 matrix (which may be NULL), compute
   *  the ImagePositionPatient and the ImageOrientationPatient.
   */
  static void ComputePositionAndOrientation(
    const double origin[3], const double matrix[16],
    double position[3], double orientation[6]);

  //! Compute the dimensions.
  /*!
   *  This will compute the dimensions of the data, given the information
   *  supplied by the reader.
   */
  virtual void ComputeDimensions(
    vtkInformation *info, int *nframes, int dims[5], double spacing[5]);

  //! Initialize the meta data and compute the slice index array.
  /*!
   *  This must be done before any of the meta data has been generated.
   *  It creates a mapping between the files and frames that will be written,
   *  and the slices that make up the image data.
   */
  virtual void InitializeMetaData(
    vtkInformation *info, vtkDICOMMetaData *meta);

  //! The meta data.
  vtkDICOMMetaData *MetaData;

  //! Whether to prefer multi-frame files over single-frame.
  int MultiFrame;

  //! Whether VTK image data is not top-to-bottom yet.
  int OriginAtBottom;

  //! Whether time is stored in slices or in scalar components.
  int TimeAsVector;

  //! Time dimension suggested by the writer.
  int TimeDimension;
  double TimeSpacing;

  //! The actual dimensions to write to the file.
  /*!
   *  The ordering of the dimensions is x,y,z,t followed by a vector
   *  dimension that encompasses everything else.  These are set by
   *  the InitializeMetaData() method.  The dimension is set to zero
   *  for any dimensions that are not used.
   */
  int Dimensions[5];
  double Spacing[5];

  //! The orientation matrix for the DICOM file.
  vtkMatrix4x4 *PatientMatrix;

  //! The file-and-frame to slice map.
  vtkIntArray *SliceIndexArray;

private:
  vtkDICOMGenerator(const vtkDICOMGenerator&);  // Not implemented.
  void operator=(const vtkDICOMGenerator&);  // Not implemented.
};

#endif // __vtkDICOMGenerator_h