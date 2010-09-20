/*
 *  IOGRenderer.h
 *  OrangeGrass
 *
 *  Created by Viacheslav Bogdanov on 07.11.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef IOGRENDERER_H_
#define IOGRENDERER_H_

#include "IOGTexture.h"
#include "IOGMaterial.h"
#include "IOGLight.h"
#include "IOGCamera.h"
#include "IOGFog.h"


enum OGRenderMode
{
	OG_RENDERMODE_GEOMETRY,
	OG_RENDERMODE_EFFECTS,
	OG_RENDERMODE_SPRITES,
	OG_RENDERMODE_SHADOWMAP
};


class IOGRenderer
{
public:
	virtual ~IOGRenderer () {}
	
	// initialize renderer.
	virtual bool Init () = 0;
	
	// set viewport.
	virtual void SetViewport (
		unsigned int _Width, 
		unsigned int _Height,
		float _fZNear,
		float _fZFar,
		float _fFOV	) = 0;

	// add rendering command.
	virtual void SetTexture (IOGTexture* _pTexture) = 0;

	// add rendering command.
	virtual void SetMaterial (IOGMaterial* _pMaterial) = 0;

	// add rendering command.
	virtual void RenderMesh (void* _pMesh) = 0;

	// Get scene light.
	virtual IOGLight* GetLight () = 0;

	// Get main camera.
	virtual IOGCamera* GetCamera () = 0;

	// Get fog.
	virtual IOGFog* GetFog () = 0;

	// start rendering mode.
	virtual void StartRenderMode(OGRenderMode _Mode) = 0;

	// finish rendering mode.
	virtual void FinishRenderMode() = 0;

	// draw shadow quad.
	virtual void DrawShadowQuad() = 0;
	
	// reset renderer pipeline.
	virtual void Reset () = 0;
};

#endif