//***************************************************************************//
// 
// * @file bePlatforTypes.h
// * @author Yahir-Juraez <yahirjuarez2002@hmail.com>
// * @date 14/09/2024
// * @brief Define basic platform types.
//
// * Define tha basic platform type variable. For porting, ths might be the
// * place to start.
//
// * @bug
// 
//***************************************************************************//

#pragma once

//***************************************************************************//
// 
// * Includes
// 
//***************************************************************************//

#include <cstdint>

//***************************************************************************//
// 
// * @brief Here we define a "intermediate" languaje. If anything changes it
// * just changes here.
// 
//***************************************************************************//

namespace beEngineSDK {
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;

//***************************************************************************//
// 
// * Basic unsigned types
// 
//***************************************************************************//

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

//***************************************************************************//
// 
// * Basic signed types
// 
//***************************************************************************//

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

//***************************************************************************//
// 
// * Character types
// 
//***************************************************************************//

#if BE_COMPILER == BE_COMPILER_MSVC
using WCHAR = wchar_t;
#else 
using WCHAR = unsigned short;
#endif 
using ANSICHAR = char;
using UNICHAR = WCHAR;
using unchar = unsigned char;

//***************************************************************************//
// 
// * NULL data type
// 
//***************************************************************************//

using TYPE_OF_NULL = int32;

//***************************************************************************//
// 
// * SIZE_T is an architecture dependent data type
// 
//***************************************************************************//

using SIZE_T = size_t;
}