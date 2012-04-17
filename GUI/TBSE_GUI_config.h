/**
 * \file TBSE_GUI_config.h
 */

#ifndef TBSE_GUI_CONFIG_H
#define TBSE_GUI_CONFIG_H

#ifdef _MSC_VER
#ifdef TBSE_GUI_EXPORTS
#define TBSE_GUI_EXPORT __declspec( dllexport )
#else
#define TBSE_GUI_EXPORT __declspec( dllimport )
#endif
#else
#define TBSE_GUI_EXPORT 
#endif

#endif
