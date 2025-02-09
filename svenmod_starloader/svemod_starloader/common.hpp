/**
 * Copyright - xWhitey, 2025.
 * common.hpp - The main file of our project with includes
 *
 * svenmod_starloader (SvenMod wrapper for StarLoader) header file
 * Authors: xWhitey. Refer to common.hpp file for dependencies and their authors.
 * Do not delete this comment block. Respect others' work!
 */

#ifdef COMMON_HPP_RECURSE_GUARD
#error Recursive header files inclusion detected in common.hpp
#else //COMMON_HPP_RECURSE_GUARD

#define COMMON_HPP_RECURSE_GUARD

#ifndef COMMON_HPP_GUARD
#define COMMON_HPP_GUARD
#pragma once

#ifdef __cplusplus

#define PLUGIN_NAME "svenmod_starloader"

//FF: we MUST define this
#define PLATFORM_EXPORTS

//FF: these too
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

//WinAPI
//Fix of some weird bug which appears only in old MSVC toolchain.
#if _MSC_VER < 1920
#ifdef no_init_all
#undef no_init_all
#endif //no_init_all
#define no_init_all
#endif //MSC_VER < 1920

#include "targetver.h"

#include <Windows.h>
#include <conio.h>

//CRT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

//Foreign stuff
#include "platform.h"
#include "IRegistry.h"
#include "ICommandLine.h"

extern void* g_pSelfHandle;

#else //!__cplusplus
#error C++ compiler required to compile common.hpp
#endif //__cplusplus

#endif //COMMON_HPP_GUARD

#undef COMMON_HPP_RECURSE_GUARD
#endif //COMMON_HPP_RECURSE_GUARD