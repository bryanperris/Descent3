/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*==========================================================================;
 *
 *  Copyright (C) 1995-1998 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       d3dcaps.h
 *  Content:    Direct3D capabilities include file
 *
 ***************************************************************************/

#ifndef _D3DCAPS_H
#define _D3DCAPS_H

/*
 *  Pull in DirectDraw include file automatically:
 */
#include <ddraw.h>

#ifndef DIRECT3D_VERSION
#define DIRECT3D_VERSION 0x0600
#endif

#pragma pack(4)

/* Description of capabilities of transform */

typedef struct _D3DTRANSFORMCAPS {
  DWORD dwSize;
  DWORD dwCaps;
} D3DTRANSFORMCAPS, *LPD3DTRANSFORMCAPS;

#define D3DTRANSFORMCAPS_CLIP 0x00000001L /* Will clip whilst transforming */

/* Description of capabilities of lighting */

typedef struct _D3DLIGHTINGCAPS {
  DWORD dwSize;
  DWORD dwCaps;          /* Lighting caps */
  DWORD dwLightingModel; /* Lighting model - RGB or mono */
  DWORD dwNumLights;     /* Number of lights that can be handled */
} D3DLIGHTINGCAPS, *LPD3DLIGHTINGCAPS;

#define D3DLIGHTINGMODEL_RGB 0x00000001L
#define D3DLIGHTINGMODEL_MONO 0x00000002L

#define D3DLIGHTCAPS_POINT 0x00000001L         /* Point lights supported */
#define D3DLIGHTCAPS_SPOT 0x00000002L          /* Spot lights supported */
#define D3DLIGHTCAPS_DIRECTIONAL 0x00000004L   /* Directional lights supported */
#define D3DLIGHTCAPS_PARALLELPOINT 0x00000008L /* Parallel point lights supported */
#if (DIRECT3D_VERSION < 0x500)
#define D3DLIGHTCAPS_GLSPOT 0x00000010L /* GL syle spot lights supported */
#endif

/* Description of capabilities for each primitive type */

typedef struct _D3DPrimCaps {
  DWORD dwSize;
  DWORD dwMiscCaps; /* Capability flags */
  DWORD dwRasterCaps;
  DWORD dwZCmpCaps;
  DWORD dwSrcBlendCaps;
  DWORD dwDestBlendCaps;
  DWORD dwAlphaCmpCaps;
  DWORD dwShadeCaps;
  DWORD dwTextureCaps;
  DWORD dwTextureFilterCaps;
  DWORD dwTextureBlendCaps;
  DWORD dwTextureAddressCaps;
  DWORD dwStippleWidth;  /* maximum width and height of */
  DWORD dwStippleHeight; /* of supported stipple (up to 32x32) */
} D3DPRIMCAPS, *LPD3DPRIMCAPS;

/* D3DPRIMCAPS dwMiscCaps */

#define D3DPMISCCAPS_MASKPLANES 0x00000001L
#define D3DPMISCCAPS_MASKZ 0x00000002L
#define D3DPMISCCAPS_LINEPATTERNREP 0x00000004L
#define D3DPMISCCAPS_CONFORMANT 0x00000008L
#define D3DPMISCCAPS_CULLNONE 0x00000010L
#define D3DPMISCCAPS_CULLCW 0x00000020L
#define D3DPMISCCAPS_CULLCCW 0x00000040L

/* D3DPRIMCAPS dwRasterCaps */

#define D3DPRASTERCAPS_DITHER 0x00000001L
#define D3DPRASTERCAPS_ROP2 0x00000002L
#define D3DPRASTERCAPS_XOR 0x00000004L
#define D3DPRASTERCAPS_PAT 0x00000008L
#define D3DPRASTERCAPS_ZTEST 0x00000010L
#define D3DPRASTERCAPS_SUBPIXEL 0x00000020L
#define D3DPRASTERCAPS_SUBPIXELX 0x00000040L
#define D3DPRASTERCAPS_FOGVERTEX 0x00000080L
#define D3DPRASTERCAPS_FOGTABLE 0x00000100L
#define D3DPRASTERCAPS_STIPPLE 0x00000200L
#define D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT 0x00000400L
#define D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT 0x00000800L
#define D3DPRASTERCAPS_ANTIALIASEDGES 0x00001000L
#define D3DPRASTERCAPS_MIPMAPLODBIAS 0x00002000L
#define D3DPRASTERCAPS_ZBIAS 0x00004000L
#define D3DPRASTERCAPS_ZBUFFERLESSHSR 0x00008000L
#define D3DPRASTERCAPS_FOGRANGE 0x00010000L
#define D3DPRASTERCAPS_ANISOTROPY 0x00020000L
#define D3DPRASTERCAPS_WBUFFER 0x00040000L
#define D3DPRASTERCAPS_TRANSLUCENTSORTINDEPENDENT 0x00080000L
#define D3DPRASTERCAPS_WFOG 0x00100000L

/* D3DPRIMCAPS dwZCmpCaps, dwAlphaCmpCaps */

#define D3DPCMPCAPS_NEVER 0x00000001L
#define D3DPCMPCAPS_LESS 0x00000002L
#define D3DPCMPCAPS_EQUAL 0x00000004L
#define D3DPCMPCAPS_LESSEQUAL 0x00000008L
#define D3DPCMPCAPS_GREATER 0x00000010L
#define D3DPCMPCAPS_NOTEQUAL 0x00000020L
#define D3DPCMPCAPS_GREATEREQUAL 0x00000040L
#define D3DPCMPCAPS_ALWAYS 0x00000080L

/* D3DPRIMCAPS dwSourceBlendCaps, dwDestBlendCaps */

#define D3DPBLENDCAPS_ZERO 0x00000001L
#define D3DPBLENDCAPS_ONE 0x00000002L
#define D3DPBLENDCAPS_SRCCOLOR 0x00000004L
#define D3DPBLENDCAPS_INVSRCCOLOR 0x00000008L
#define D3DPBLENDCAPS_SRCALPHA 0x00000010L
#define D3DPBLENDCAPS_INVSRCALPHA 0x00000020L
#define D3DPBLENDCAPS_DESTALPHA 0x00000040L
#define D3DPBLENDCAPS_INVDESTALPHA 0x00000080L
#define D3DPBLENDCAPS_DESTCOLOR 0x00000100L
#define D3DPBLENDCAPS_INVDESTCOLOR 0x00000200L
#define D3DPBLENDCAPS_SRCALPHASAT 0x00000400L
#define D3DPBLENDCAPS_BOTHSRCALPHA 0x00000800L
#define D3DPBLENDCAPS_BOTHINVSRCALPHA 0x00001000L

/* D3DPRIMCAPS dwShadeCaps */

#define D3DPSHADECAPS_COLORFLATMONO 0x00000001L
#define D3DPSHADECAPS_COLORFLATRGB 0x00000002L
#define D3DPSHADECAPS_COLORGOURAUDMONO 0x00000004L
#define D3DPSHADECAPS_COLORGOURAUDRGB 0x00000008L
#define D3DPSHADECAPS_COLORPHONGMONO 0x00000010L
#define D3DPSHADECAPS_COLORPHONGRGB 0x00000020L

#define D3DPSHADECAPS_SPECULARFLATMONO 0x00000040L
#define D3DPSHADECAPS_SPECULARFLATRGB 0x00000080L
#define D3DPSHADECAPS_SPECULARGOURAUDMONO 0x00000100L
#define D3DPSHADECAPS_SPECULARGOURAUDRGB 0x00000200L
#define D3DPSHADECAPS_SPECULARPHONGMONO 0x00000400L
#define D3DPSHADECAPS_SPECULARPHONGRGB 0x00000800L

#define D3DPSHADECAPS_ALPHAFLATBLEND 0x00001000L
#define D3DPSHADECAPS_ALPHAFLATSTIPPLED 0x00002000L
#define D3DPSHADECAPS_ALPHAGOURAUDBLEND 0x00004000L
#define D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED 0x00008000L
#define D3DPSHADECAPS_ALPHAPHONGBLEND 0x00010000L
#define D3DPSHADECAPS_ALPHAPHONGSTIPPLED 0x00020000L

#define D3DPSHADECAPS_FOGFLAT 0x00040000L
#define D3DPSHADECAPS_FOGGOURAUD 0x00080000L
#define D3DPSHADECAPS_FOGPHONG 0x00100000L

/* D3DPRIMCAPS dwTextureCaps */

/*
 * Perspective-correct texturing is supported
 */
#define D3DPTEXTURECAPS_PERSPECTIVE 0x00000001L

/*
 * Power-of-2 texture dimensions are required
 */
#define D3DPTEXTURECAPS_POW2 0x00000002L

/*
 * Alpha in texture pixels is supported
 */
#define D3DPTEXTURECAPS_ALPHA 0x00000004L

/*
 * Color-keyed textures are supported
 */
#define D3DPTEXTURECAPS_TRANSPARENCY 0x00000008L

/*
 * obsolete, see D3DPTADDRESSCAPS_BORDER
 */
#define D3DPTEXTURECAPS_BORDER 0x00000010L

/*
 * Only square textures are supported
 */
#define D3DPTEXTURECAPS_SQUAREONLY 0x00000020L

/*
 * Texture indices are not scaled by the texture size prior
 * to interpolation.
 */
#define D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE 0x00000040L

/*
 * Device can draw alpha from texture palettes
 */
#define D3DPTEXTURECAPS_ALPHAPALETTE 0x00000080L

/* D3DPRIMCAPS dwTextureFilterCaps */

#define D3DPTFILTERCAPS_NEAREST 0x00000001L
#define D3DPTFILTERCAPS_LINEAR 0x00000002L
#define D3DPTFILTERCAPS_MIPNEAREST 0x00000004L
#define D3DPTFILTERCAPS_MIPLINEAR 0x00000008L
#define D3DPTFILTERCAPS_LINEARMIPNEAREST 0x00000010L
#define D3DPTFILTERCAPS_LINEARMIPLINEAR 0x00000020L

/* Device3 Min Filter */
#define D3DPTFILTERCAPS_MINFPOINT 0x00000100L
#define D3DPTFILTERCAPS_MINFLINEAR 0x00000200L
#define D3DPTFILTERCAPS_MINFANISOTROPIC 0x00000400L

/* Device3 Mip Filter */
#define D3DPTFILTERCAPS_MIPFPOINT 0x00010000L
#define D3DPTFILTERCAPS_MIPFLINEAR 0x00020000L

/* Device3 Mag Filter */
#define D3DPTFILTERCAPS_MAGFPOINT 0x01000000L
#define D3DPTFILTERCAPS_MAGFLINEAR 0x02000000L
#define D3DPTFILTERCAPS_MAGFANISOTROPIC 0x04000000L
#define D3DPTFILTERCAPS_MAGFAFLATCUBIC 0x08000000L
#define D3DPTFILTERCAPS_MAGFGAUSSIANCUBIC 0x10000000L

/* D3DPRIMCAPS dwTextureBlendCaps */

#define D3DPTBLENDCAPS_DECAL 0x00000001L
#define D3DPTBLENDCAPS_MODULATE 0x00000002L
#define D3DPTBLENDCAPS_DECALALPHA 0x00000004L
#define D3DPTBLENDCAPS_MODULATEALPHA 0x00000008L
#define D3DPTBLENDCAPS_DECALMASK 0x00000010L
#define D3DPTBLENDCAPS_MODULATEMASK 0x00000020L
#define D3DPTBLENDCAPS_COPY 0x00000040L
#define D3DPTBLENDCAPS_ADD 0x00000080L

/* D3DPRIMCAPS dwTextureAddressCaps */
#define D3DPTADDRESSCAPS_WRAP 0x00000001L
#define D3DPTADDRESSCAPS_MIRROR 0x00000002L
#define D3DPTADDRESSCAPS_CLAMP 0x00000004L
#define D3DPTADDRESSCAPS_BORDER 0x00000008L
#define D3DPTADDRESSCAPS_INDEPENDENTUV 0x00000010L

/* D3DDEVICEDESC dwStencilCaps */

#define D3DSTENCILCAPS_KEEP 0x00000001L
#define D3DSTENCILCAPS_ZERO 0x00000002L
#define D3DSTENCILCAPS_REPLACE 0x00000004L
#define D3DSTENCILCAPS_INCRSAT 0x00000008L
#define D3DSTENCILCAPS_DECRSAT 0x00000010L
#define D3DSTENCILCAPS_INVERT 0x00000020L
#define D3DSTENCILCAPS_INCR 0x00000040L
#define D3DSTENCILCAPS_DECR 0x00000080L

/* D3DDEVICEDESC dwTextureOpCaps */

#define D3DTEXOPCAPS_DISABLE 0x00000001L
#define D3DTEXOPCAPS_SELECTARG1 0x00000002L
#define D3DTEXOPCAPS_SELECTARG2 0x00000004L
#define D3DTEXOPCAPS_MODULATE 0x00000008L
#define D3DTEXOPCAPS_MODULATE2X 0x00000010L
#define D3DTEXOPCAPS_MODULATE4X 0x00000020L
#define D3DTEXOPCAPS_ADD 0x00000040L
#define D3DTEXOPCAPS_ADDSIGNED 0x00000080L
#define D3DTEXOPCAPS_ADDSIGNED2X 0x00000100L
#define D3DTEXOPCAPS_SUBTRACT 0x00000200L
#define D3DTEXOPCAPS_ADDSMOOTH 0x00000400L
#define D3DTEXOPCAPS_BLENDDIFFUSEALPHA 0x00000800L
#define D3DTEXOPCAPS_BLENDTEXTUREALPHA 0x00001000L
#define D3DTEXOPCAPS_BLENDFACTORALPHA 0x00002000L
#define D3DTEXOPCAPS_BLENDTEXTUREALPHAPM 0x00004000L
#define D3DTEXOPCAPS_BLENDCURRENTALPHA 0x00008000L
#define D3DTEXOPCAPS_PREMODULATE 0x00010000L
#define D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR 0x00020000L
#define D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA 0x00040000L
#define D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR 0x00080000L
#define D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA 0x00100000L
#define D3DTEXOPCAPS_BUMPENVMAP 0x00200000L
#define D3DTEXOPCAPS_BUMPENVMAPLUMINANCE 0x00400000L
#define D3DTEXOPCAPS_DOTPRODUCT3 0x00800000L

/* D3DDEVICEDESC dwFVFCaps flags */

#define D3DFVFCAPS_TEXCOORDCOUNTMASK 0x0000ffffL  /* mask for texture coordinate count field */
#define D3DFVFCAPS_DONOTSTRIPELEMENTS 0x00080000L /* Device prefers that vertex elements not be stripped */

/*
 * Description for a device.
 * This is used to describe a device that is to be created or to query
 * the current device.
 */
typedef struct _D3DDeviceDesc {
  DWORD dwSize;                      /* Size of D3DDEVICEDESC structure */
  DWORD dwFlags;                     /* Indicates which fields have valid data */
  D3DCOLORMODEL dcmColorModel;       /* Color model of device */
  DWORD dwDevCaps;                   /* Capabilities of device */
  D3DTRANSFORMCAPS dtcTransformCaps; /* Capabilities of transform */
  BOOL bClipping;                    /* Device can do 3D clipping */
  D3DLIGHTINGCAPS dlcLightingCaps;   /* Capabilities of lighting */
  D3DPRIMCAPS dpcLineCaps;
  D3DPRIMCAPS dpcTriCaps;
  DWORD dwDeviceRenderBitDepth;  /* One of DDBB_8, 16, etc.. */
  DWORD dwDeviceZBufferBitDepth; /* One of DDBD_16, 32, etc.. */
  DWORD dwMaxBufferSize;         /* Maximum execute buffer size */
  DWORD dwMaxVertexCount;        /* Maximum vertex count */
#if (DIRECT3D_VERSION >= 0x0500)
  // *** New fields for DX5 *** //

  // Width and height caps are 0 for legacy HALs.
  DWORD dwMinTextureWidth, dwMinTextureHeight;
  DWORD dwMaxTextureWidth, dwMaxTextureHeight;
  DWORD dwMinStippleWidth, dwMaxStippleWidth;
  DWORD dwMinStippleHeight, dwMaxStippleHeight;
#endif /* DIRECT3D_VERSION >= 0x0500 */

#if (DIRECT3D_VERSION >= 0x0600)
  // New fields for DX6
  DWORD dwMaxTextureRepeat;
  DWORD dwMaxTextureAspectRatio;
  DWORD dwMaxAnisotropy;

  // Guard band that the rasterizer can accommodate
  // Screen-space vertices inside this space but outside the viewport
  // will get clipped properly.
  D3DVALUE dvGuardBandLeft;
  D3DVALUE dvGuardBandTop;
  D3DVALUE dvGuardBandRight;
  D3DVALUE dvGuardBandBottom;

  D3DVALUE dvExtentsAdjust;
  DWORD dwStencilCaps;

  DWORD dwFVFCaps; /* low 4 bits: 0 implies TLVERTEX only, 1..8 imply FVF aware */
  DWORD dwTextureOpCaps;
  WORD wMaxTextureBlendStages;
  WORD wMaxSimultaneousTextures;

#endif /* DIRECT3D_VERSION >= 0x0600 */
} D3DDEVICEDESC, *LPD3DDEVICEDESC;

#define D3DDEVICEDESCSIZE (sizeof(D3DDEVICEDESC))

typedef HRESULT(CALLBACK *LPD3DENUMDEVICESCALLBACK)(GUID FAR *lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName,
                                                    LPD3DDEVICEDESC, LPD3DDEVICEDESC, LPVOID);

/* D3DDEVICEDESC dwFlags indicating valid fields */

#define D3DDD_COLORMODEL 0x00000001L            /* dcmColorModel is valid */
#define D3DDD_DEVCAPS 0x00000002L               /* dwDevCaps is valid */
#define D3DDD_TRANSFORMCAPS 0x00000004L         /* dtcTransformCaps is valid */
#define D3DDD_LIGHTINGCAPS 0x00000008L          /* dlcLightingCaps is valid */
#define D3DDD_BCLIPPING 0x00000010L             /* bClipping is valid */
#define D3DDD_LINECAPS 0x00000020L              /* dpcLineCaps is valid */
#define D3DDD_TRICAPS 0x00000040L               /* dpcTriCaps is valid */
#define D3DDD_DEVICERENDERBITDEPTH 0x00000080L  /* dwDeviceRenderBitDepth is valid */
#define D3DDD_DEVICEZBUFFERBITDEPTH 0x00000100L /* dwDeviceZBufferBitDepth is valid */
#define D3DDD_MAXBUFFERSIZE 0x00000200L         /* dwMaxBufferSize is valid */
#define D3DDD_MAXVERTEXCOUNT 0x00000400L        /* dwMaxVertexCount is valid */

/* D3DDEVICEDESC dwDevCaps flags */

#define D3DDEVCAPS_FLOATTLVERTEX 0x00000001L   /* Device accepts floating point */
                                               /* for post-transform vertex data */
#define D3DDEVCAPS_SORTINCREASINGZ 0x00000002L /* Device needs data sorted for increasing Z */
#define D3DDEVCAPS_SORTDECREASINGZ 0X00000004L /* Device needs data sorted for decreasing Z */
#define D3DDEVCAPS_SORTEXACT 0x00000008L       /* Device needs data sorted exactly */

#define D3DDEVCAPS_EXECUTESYSTEMMEMORY 0x00000010L     /* Device can use execute buffers from system memory */
#define D3DDEVCAPS_EXECUTEVIDEOMEMORY 0x00000020L      /* Device can use execute buffers from video memory */
#define D3DDEVCAPS_TLVERTEXSYSTEMMEMORY 0x00000040L    /* Device can use TL buffers from system memory */
#define D3DDEVCAPS_TLVERTEXVIDEOMEMORY 0x00000080L     /* Device can use TL buffers from video memory */
#define D3DDEVCAPS_TEXTURESYSTEMMEMORY 0x00000100L     /* Device can texture from system memory */
#define D3DDEVCAPS_TEXTUREVIDEOMEMORY 0x00000200L      /* Device can texture from device memory */
#define D3DDEVCAPS_DRAWPRIMTLVERTEX 0x00000400L        /* Device can draw TLVERTEX primitives */
#define D3DDEVCAPS_CANRENDERAFTERFLIP 0x00000800L      /* Device can render without waiting for flip to complete */
#define D3DDEVCAPS_TEXTURENONLOCALVIDMEM 0x00001000L   /* Device can texture from nonlocal video memory */
#define D3DDEVCAPS_DRAWPRIMITIVES2 0x00002000L         /* Device can support DrawPrimitives2 */
#define D3DDEVCAPS_SEPARATETEXTUREMEMORIES 0x00004000L /* Device is texturing from separate memory pools */

#define D3DFDS_COLORMODEL 0x00000001L         /* Match color model */
#define D3DFDS_GUID 0x00000002L               /* Match guid */
#define D3DFDS_HARDWARE 0x00000004L           /* Match hardware/software */
#define D3DFDS_TRIANGLES 0x00000008L          /* Match in triCaps */
#define D3DFDS_LINES 0x00000010L              /* Match in lineCaps  */
#define D3DFDS_MISCCAPS 0x00000020L           /* Match primCaps.dwMiscCaps */
#define D3DFDS_RASTERCAPS 0x00000040L         /* Match primCaps.dwRasterCaps */
#define D3DFDS_ZCMPCAPS 0x00000080L           /* Match primCaps.dwZCmpCaps */
#define D3DFDS_ALPHACMPCAPS 0x00000100L       /* Match primCaps.dwAlphaCmpCaps */
#define D3DFDS_SRCBLENDCAPS 0x00000200L       /* Match primCaps.dwSourceBlendCaps */
#define D3DFDS_DSTBLENDCAPS 0x00000400L       /* Match primCaps.dwDestBlendCaps */
#define D3DFDS_SHADECAPS 0x00000800L          /* Match primCaps.dwShadeCaps */
#define D3DFDS_TEXTURECAPS 0x00001000L        /* Match primCaps.dwTextureCaps */
#define D3DFDS_TEXTUREFILTERCAPS 0x00002000L  /* Match primCaps.dwTextureFilterCaps */
#define D3DFDS_TEXTUREBLENDCAPS 0x00004000L   /* Match primCaps.dwTextureBlendCaps */
#define D3DFDS_TEXTUREADDRESSCAPS 0x00008000L /* Match primCaps.dwTextureBlendCaps */

/*
 * FindDevice arguments
 */
typedef struct _D3DFINDDEVICESEARCH {
  DWORD dwSize;
  DWORD dwFlags;
  BOOL bHardware;
  D3DCOLORMODEL dcmColorModel;
  GUID guid;
  DWORD dwCaps;
  D3DPRIMCAPS dpcPrimCaps;
} D3DFINDDEVICESEARCH, *LPD3DFINDDEVICESEARCH;

typedef struct _D3DFINDDEVICERESULT {
  DWORD dwSize;
  GUID guid;              /* guid which matched */
  D3DDEVICEDESC ddHwDesc; /* hardware D3DDEVICEDESC */
  D3DDEVICEDESC ddSwDesc; /* software D3DDEVICEDESC */
} D3DFINDDEVICERESULT, *LPD3DFINDDEVICERESULT;

/*
 * Description of execute buffer.
 */
typedef struct _D3DExecuteBufferDesc {
  DWORD dwSize;       /* size of this structure */
  DWORD dwFlags;      /* flags indicating which fields are valid */
  DWORD dwCaps;       /* capabilities of execute buffer */
  DWORD dwBufferSize; /* size of execute buffer data */
  LPVOID lpData;      /* pointer to actual data */
} D3DEXECUTEBUFFERDESC, *LPD3DEXECUTEBUFFERDESC;

/* D3DEXECUTEBUFFER dwFlags indicating valid fields */

#define D3DDEB_BUFSIZE 0x00000001l /* buffer size valid */
#define D3DDEB_CAPS 0x00000002l    /* caps valid */
#define D3DDEB_LPDATA 0x00000004l  /* lpData valid */

/* D3DEXECUTEBUFFER dwCaps */

#define D3DDEBCAPS_SYSTEMMEMORY 0x00000001l /* buffer in system memory */
#define D3DDEBCAPS_VIDEOMEMORY 0x00000002l  /* buffer in device memory */
#define D3DDEBCAPS_MEM (D3DDEBCAPS_SYSTEMMEMORY | D3DDEBCAPS_VIDEOMEMORY)

#pragma pack()

#endif /* _D3DCAPS_H_ */
