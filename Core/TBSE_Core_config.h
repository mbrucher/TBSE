/**
 * \file TBSE_Core_config.h
 */

#ifndef TBSE_CORE_CONFIG_H
#define TBSE_CORE_CONFIG_H

#ifdef _MSC_VER
#ifdef TBSE_Core_EXPORTS
#define TBSE_Core_EXPORT __declspec( dllexport )
#else
#define TBSE_Core_EXPORT __declspec( dllimport )
#endif
#else
#define TBSE_Core_EXPORT 
#endif

#endif
