/**
 * \file TGSE_Core_config.h
 */

#ifndef TGSE_CORE_CONFIG_H
#define TGSE_CORE_CONFIG_H

#ifdef _MSC_VER
#ifdef TGSE_Core_EXPORTS
#define TGSE_Core_EXPORT __declspec( dllexport )
#else
#define TGSE_Core_EXPORT __declspec( dllimport )
#endif
#else
#define TGSE_Core_EXPORT 
#endif

#endif
