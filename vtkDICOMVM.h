/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2013 David Gobbi
  All rights reserved.
  See Copyright.txt or http://www.cognitive-antics.net/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __vtkDICOMVM_h
#define __vtkDICOMVM_h

#include <vtkSystemIncludes.h>
#include "vtkDICOMModule.h"

//! VMs (Value Multiplicities)
class VTK_DICOM_EXPORT vtkDICOMVM
{
public:
  enum EnumType
  {
    M0    = 0x0000,
    M0T1  = 0x0001,
    M0T2  = 0x0002,
    M0T3  = 0x0003,
    M0T4  = 0x0004,
    M0T5  = 0x0005,
    M0T6  = 0x0006,
    M0T7  = 0x0007,
    M0T8  = 0x0008,
    M0T9  = 0x0009,
    M0T10 = 0x000A,
    M0T11 = 0x000B,
    M0T12 = 0x000C,
    M0T13 = 0x000D,
    M0T14 = 0x000E,
    M0T15 = 0x000F,
    M0T16 = 0x0010,
    M0T17 = 0x0011,
    M0T18 = 0x0012,
    M0T19 = 0x0013,
    M0T20 = 0x0014,
    M0T21 = 0x0015,
    M0T22 = 0x0016,
    M0T23 = 0x0017,
    M0T24 = 0x0018,
    M0T25 = 0x0019,
    M0T26 = 0x001A,
    M0T27 = 0x001B,
    M0T28 = 0x001C,
    M0T29 = 0x001D,
    M0T30 = 0x001E,
    M0T31 = 0x001F,
    M0T32 = 0x0020,
    M0T63 = 0x003F,
    M0T64 = 0x0040,
    M0T99 = 0x0063,
    M0T4N = 0x00FC,
    M0T3N = 0x00FD,
    M0T2N = 0x00FE,
    M0TN  = 0x00FF,
    M1    = 0x0101,
    M1T2  = 0x0102,
    M1T3  = 0x0103,
    M1T4  = 0x0104,
    M1T5  = 0x0105,
    M1T6  = 0x0106,
    M1T7  = 0x0107,
    M1T8  = 0x0108,
    M1T9  = 0x0109,
    M1T10 = 0x010A,
    M1T11 = 0x010B,
    M1T12 = 0x010C,
    M1T13 = 0x010D,
    M1T14 = 0x010E,
    M1T15 = 0x010F,
    M1T16 = 0x0110,
    M1T17 = 0x0111,
    M1T18 = 0x0112,
    M1T19 = 0x0113,
    M1T20 = 0x0114,
    M1T21 = 0x0115,
    M1T22 = 0x0116,
    M1T23 = 0x0117,
    M1T24 = 0x0118,
    M1T25 = 0x0119,
    M1T26 = 0x011A,
    M1T27 = 0x011B,
    M1T28 = 0x011C,
    M1T29 = 0x011D,
    M1T30 = 0x011E,
    M1T31 = 0x011F,
    M1T32 = 0x0120,
    M1T63 = 0x013F,
    M1T64 = 0x0140,
    M1T99 = 0x0163,
    M1TN  = 0x01FF,
    M2    = 0x0202,
    M2T3  = 0x0203,
    M2T4  = 0x0204,
    M2T5  = 0x0205,
    M2T6  = 0x0206,
    M2T7  = 0x0207,
    M2T8  = 0x0208,
    M2T9  = 0x0209,
    M2T10 = 0x020A,
    M2T11 = 0x020B,
    M2T12 = 0x020C,
    M2T13 = 0x020D,
    M2T14 = 0x020E,
    M2T15 = 0x020F,
    M2T16 = 0x0210,
    M2T17 = 0x0211,
    M2T18 = 0x0212,
    M2T19 = 0x0213,
    M2T20 = 0x0214,
    M2T21 = 0x0215,
    M2T22 = 0x0216,
    M2T23 = 0x0217,
    M2T24 = 0x0218,
    M2T25 = 0x0219,
    M2T26 = 0x021A,
    M2T27 = 0x021B,
    M2T28 = 0x021C,
    M2T29 = 0x021D,
    M2T30 = 0x021E,
    M2T31 = 0x021F,
    M2T32 = 0x0220,
    M2T63 = 0x023F,
    M2T64 = 0x0240,
    M2T99 = 0x0263,
    M2T2N = 0x02FE,
    M2TN  = 0x02FF,
    M3    = 0x0303,
    M3T4  = 0x0304,
    M3T5  = 0x0305,
    M3T6  = 0x0306,
    M3T7  = 0x0307,
    M3T8  = 0x0308,
    M3T9  = 0x0309,
    M3T10 = 0x030A,
    M3T11 = 0x030B,
    M3T12 = 0x030C,
    M3T13 = 0x030D,
    M3T14 = 0x030E,
    M3T15 = 0x030F,
    M3T16 = 0x0310,
    M3T17 = 0x0311,
    M3T18 = 0x0312,
    M3T19 = 0x0313,
    M3T20 = 0x0314,
    M3T21 = 0x0315,
    M3T22 = 0x0316,
    M3T23 = 0x0317,
    M3T24 = 0x0318,
    M3T25 = 0x0319,
    M3T26 = 0x031A,
    M3T27 = 0x031B,
    M3T28 = 0x031C,
    M3T29 = 0x031D,
    M3T30 = 0x031E,
    M3T31 = 0x031F,
    M3T32 = 0x0320,
    M3T63 = 0x033F,
    M3T64 = 0x0340,
    M3T99 = 0x0363,
    M3T3N = 0x03FD,
    M3TN  = 0x03FF,
    M4    = 0x0404,
    M4T5  = 0x0405,
    M4T6  = 0x0406,
    M4T7  = 0x0407,
    M4T8  = 0x0408,
    M4T9  = 0x0409,
    M4T10 = 0x040A,
    M4T11 = 0x040B,
    M4T12 = 0x040C,
    M4T13 = 0x040D,
    M4T14 = 0x040E,
    M4T15 = 0x040F,
    M4T16 = 0x0410,
    M4T17 = 0x0411,
    M4T18 = 0x0412,
    M4T19 = 0x0413,
    M4T20 = 0x0414,
    M4T21 = 0x0415,
    M4T22 = 0x0416,
    M4T23 = 0x0417,
    M4T24 = 0x0418,
    M4T25 = 0x0419,
    M4T26 = 0x041A,
    M4T27 = 0x041B,
    M4T28 = 0x041C,
    M4T29 = 0x041D,
    M4T30 = 0x041E,
    M4T31 = 0x041F,
    M4T32 = 0x0420,
    M4T63 = 0x043F,
    M4T64 = 0x0440,
    M4T99 = 0x0463,
    M4T4N = 0x04FC,
    M4TN  = 0x04FF,
    M5    = 0x0505,
    M5T6  = 0x0506,
    M5T7  = 0x0507,
    M5T8  = 0x0508,
    M5T9  = 0x0509,
    M5T10 = 0x050A,
    M5T11 = 0x050B,
    M5T12 = 0x050C,
    M5T13 = 0x050D,
    M5T14 = 0x050E,
    M5T15 = 0x050F,
    M5T16 = 0x0510,
    M5T17 = 0x0511,
    M5T18 = 0x0512,
    M5T19 = 0x0513,
    M5T20 = 0x0514,
    M5T21 = 0x0515,
    M5T22 = 0x0516,
    M5T23 = 0x0517,
    M5T24 = 0x0518,
    M5T25 = 0x0519,
    M5T26 = 0x051A,
    M5T27 = 0x051B,
    M5T28 = 0x051C,
    M5T29 = 0x051D,
    M5T30 = 0x051E,
    M5T31 = 0x051F,
    M5T32 = 0x0520,
    M5T63 = 0x053F,
    M5T64 = 0x0540,
    M5T99 = 0x0563,
    M5T5N = 0x05FB,
    M5TN  = 0x05FF,
    M6    = 0x0606,
    M6T7  = 0x0607,
    M6T8  = 0x0608,
    M6T9  = 0x0609,
    M6T10 = 0x060A,
    M6T11 = 0x060B,
    M6T12 = 0x060C,
    M6T13 = 0x060D,
    M6T14 = 0x060E,
    M6T15 = 0x060F,
    M6T16 = 0x0610,
    M6T17 = 0x0611,
    M6T18 = 0x0612,
    M6T19 = 0x0613,
    M6T20 = 0x0614,
    M6T21 = 0x0615,
    M6T22 = 0x0616,
    M6T23 = 0x0617,
    M6T24 = 0x0618,
    M6T25 = 0x0619,
    M6T26 = 0x061A,
    M6T27 = 0x061B,
    M6T28 = 0x061C,
    M6T29 = 0x061D,
    M6T30 = 0x061E,
    M6T31 = 0x061F,
    M6T32 = 0x0620,
    M6T63 = 0x063F,
    M6T64 = 0x0640,
    M6T99 = 0x0663,
    M6T6N = 0x06FA,
    M6TN  = 0x06FF,
    M7    = 0x0707,
    M7T8  = 0x0708,
    M7T9  = 0x0709,
    M7T10 = 0x070A,
    M7T11 = 0x070B,
    M7T12 = 0x070C,
    M7T13 = 0x070D,
    M7T14 = 0x070E,
    M7T15 = 0x070F,
    M7T16 = 0x0710,
    M7T17 = 0x0711,
    M7T18 = 0x0712,
    M7T19 = 0x0713,
    M7T20 = 0x0714,
    M7T21 = 0x0715,
    M7T22 = 0x0716,
    M7T23 = 0x0717,
    M7T24 = 0x0718,
    M7T25 = 0x0719,
    M7T26 = 0x071A,
    M7T27 = 0x071B,
    M7T28 = 0x071C,
    M7T29 = 0x071D,
    M7T30 = 0x071E,
    M7T31 = 0x071F,
    M7T32 = 0x0720,
    M7T63 = 0x073F,
    M7T64 = 0x0740,
    M7T99 = 0x0763,
    M7T7N = 0x07F9,
    M7TN  = 0x07FF,
    M8    = 0x0808,
    M8T9  = 0x0809,
    M8T10 = 0x080A,
    M8T11 = 0x080B,
    M8T12 = 0x080C,
    M8T13 = 0x080D,
    M8T14 = 0x080E,
    M8T15 = 0x080F,
    M8T16 = 0x0810,
    M8T17 = 0x0811,
    M8T18 = 0x0812,
    M8T19 = 0x0813,
    M8T20 = 0x0814,
    M8T21 = 0x0815,
    M8T22 = 0x0816,
    M8T23 = 0x0817,
    M8T24 = 0x0818,
    M8T25 = 0x0819,
    M8T26 = 0x081A,
    M8T27 = 0x081B,
    M8T28 = 0x081C,
    M8T29 = 0x081D,
    M8T30 = 0x081E,
    M8T31 = 0x081F,
    M8T32 = 0x0820,
    M8T63 = 0x083F,
    M8T64 = 0x0840,
    M8T99 = 0x0863,
    M8T8N = 0x08F8,
    M8TN  = 0x08FF,
    M9    = 0x0909,
    M9T10 = 0x090A,
    M9T11 = 0x090B,
    M9T12 = 0x090C,
    M9T13 = 0x090D,
    M9T14 = 0x090E,
    M9T15 = 0x090F,
    M9T16 = 0x0910,
    M9T17 = 0x0911,
    M9T18 = 0x0912,
    M9T19 = 0x0913,
    M9T20 = 0x0914,
    M9T21 = 0x0915,
    M9T22 = 0x0916,
    M9T23 = 0x0917,
    M9T24 = 0x0918,
    M9T25 = 0x0919,
    M9T26 = 0x091A,
    M9T27 = 0x091B,
    M9T28 = 0x091C,
    M9T29 = 0x091D,
    M9T30 = 0x091E,
    M9T31 = 0x091F,
    M9T32 = 0x0920,
    M9T63 = 0x093F,
    M9T64 = 0x0940,
    M9T99 = 0x0963,
    M9T9N = 0x09F7,
    M9TN  = 0x09FF,
    M10   = 0x0A0A,
    M10TN = 0x0AFF,
    M11   = 0x0B0B,
    M11TN = 0x0BFF,
    M12   = 0x0C0C,
    M12TN = 0x0CFF,
    M13   = 0x0D0D,
    M13TN = 0x0DFF,
    M14   = 0x0E0E,
    M14TN = 0x0EFF,
    M15   = 0x0F0F,
    M15TN = 0x0FFF,
    M16   = 0x1010,
    M16TN = 0x10FF,
    M17   = 0x1111,
    M17TN = 0x11FF,
    M18   = 0x1212,
    M18TN = 0x12FF,
    M19   = 0x1313,
    M19TN = 0x13FF,
    M20   = 0x1414,
    M20TN = 0x14FF,
    M21   = 0x1515,
    M21TN = 0x15FF,
    M22   = 0x1616,
    M22TN = 0x16FF,
    M23   = 0x1717,
    M23TN = 0x17FF,
    M24   = 0x1818,
    M24TN = 0x18FF,
    M25   = 0x1919,
    M25TN = 0x19FF,
    M26   = 0x1A1A,
    M26TN = 0x1AFF,
    M27   = 0x1B1B,
    M27TN = 0x1BFF,
    M28   = 0x1C1C,
    M28TN = 0x1CFF,
    M29   = 0x1D1D,
    M29TN = 0x1DFF,
    M30   = 0x1E1E,
    M30TN = 0x1EFF,
    M31   = 0x1F1F,
    M31TN = 0x1FFF,
    M32   = 0x2020,
    M32TN = 0x20FF,
    M63   = 0x3F3F,
    M63TN = 0x3FFF,
    M64   = 0x4040,
    M64TN = 0x40FF,
    M99   = 0x6363,
    M99TN = 0x63FF,
    M100  = 0x6464,
    M127  = 0x7F7F,
    M128  = 0x8080,
    M255  = 0x80FF,
    M256  = 0x8100,
    M511  = 0x81FF,
    M512  = 0x8200,
    M768  = 0x8300,
    M1024 = 0x8400,
    M2048 = 0x8800,
    M4096 = 0x9000,
    M8192 = 0xA000
  };

  //! Construct an empty, invalid VM.
  vtkDICOMVM() : Key(0) {}

  //! Construct a VM from a VM enum constant.
  vtkDICOMVM(EnumType vm) : Key(static_cast<unsigned short>(vm)) {};

  //! Check validity of this VM.
  bool IsValid() const { return (this->Key != 0); }

  //! Get the minimum allowed number of values
  int GetMin() const {
    if ((this->Key & 0x8000) != 0) { return (this->Key & 0x7fff); }
    else { return (this->Key >> 8); } }

  //! Get the maximum allowed number of values, -1 if unlimited
  int GetMax() const {
    if ((this->Key & 0x8000) != 0) { return (this->Key & 0x7fff); }
    else { return ((this->Key & 0x80) == 0 ? (this->Key & 0xff) : -1); } }

  //! Get the step between allowed values.
  int GetStep() const {
    if ((this->Key & 0x8000) != 0) { return 1; }
    else { return ((this->Key & 0x80) == 0 ? 1 : ((-this->Key) & 0xff)); } }

  bool operator==(vtkDICOMVM b) const { return (this->Key == b.Key); }
  bool operator!=(vtkDICOMVM b) const { return (this->Key != b.Key); }
  bool operator<=(vtkDICOMVM a) const { return (this->Key <= a.Key); }
  bool operator>=(vtkDICOMVM a) const { return (this->Key >= a.Key); }
  bool operator<(vtkDICOMVM a) const { return (this->Key < a.Key); }
  bool operator>(vtkDICOMVM a) const { return (this->Key > a.Key); }

private:
  unsigned short Key;
};

VTK_DICOM_EXPORT ostream& operator<<(ostream& o, const vtkDICOMVM& a);

#endif /* __vtkDICOMVM_h */
