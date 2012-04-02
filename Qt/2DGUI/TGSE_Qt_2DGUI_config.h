/**
 * \file TGSE_Qt_2DGUI_config.h
 */

#ifndef TGSE_QT_2DGUI_CONFIG_H
#define TGSE_QT_2DGUI_CONFIG_H

#ifdef _MSC_VER
#ifdef TGSE_Qt_2DGUI_EXPORTS
#define TGSE_Qt_2DGUI_EXPORT __declspec( dllexport )
#else
#define TGSE_Qt_2DGUI_EXPORT __declspec( dllimport )
#endif
#else
#define TGSE_Qt_2DGUI_EXPORT 
#endif

#endif
