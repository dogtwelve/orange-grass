/*
 *  ogrenderer.h
 *  OrangeGrass
 *
 *  Created by Viacheslav Bogdanov on 07.11.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef OGRENDERER_H_
#define OGRENDERER_H_

#include "IOGRenderer.h"
#include "IOGStatistics.h"
#include "OpenGL2.h"
#include "ogmesh.h"
#include "ogrendertarget.h"
#include "UI.h"


class COGRenderer : public IOGRenderer
{
public:
	COGRenderer ();
	virtual ~COGRenderer ();
	
	// initialize renderer.
	virtual bool Init ();
	
	// set viewport.
	virtual void SetViewport (
		unsigned int _Width, 
		unsigned int _Height,
		float _fZNear,
		float _fZFar,
		float _fFOV);

	// add rendering command.
	virtual void SetTexture (IOGTexture* _pTexture);

	// add rendering command.
	virtual void SetMaterial (IOGMaterial* _pMaterial);

	// add rendering command.
	virtual void RenderMesh (void* _pMesh);

	// clear frame buffer with the given color
	virtual void ClearFrame (const Vec4& _vClearColor);

	// Get scene light.
	virtual IOGLight* GetLight ();

	// Get main camera.
	virtual IOGCamera* GetCamera ();

	// Get fog.
	virtual IOGFog* GetFog ();

	// start rendering mode.
	virtual void StartRenderMode(OGRenderMode _Mode);

	// finish rendering mode.
	virtual void FinishRenderMode();

	// reset renderer pipeline.
	virtual void Reset ();

    // Unproject screen coords.
    virtual Vec3 UnprojectCoords (int _X, int _Y);

    // Display string.
    virtual void DisplayString (
		const Vec2& _vPos, 
		float _fScale, 
		unsigned int Colour, 
		const char * const pszFormat, ...);
	
private:

    IOGTexture*         m_pCurTexture;
    IOGMaterial*        m_pCurMaterial;
    COGVertexBuffers*	m_pCurMesh;
	IOGStatistics*		m_pStats;
	IOGLight*			m_pLight;
	IOGCamera*			m_pCamera;
	IOGFog*				m_pFog;
	CDisplayText*		m_pText;
	MATRIX				m_mOrthoProj;
	MATRIX				m_mProjection;
	unsigned int		m_Width; 
	unsigned int		m_Height;
	float				m_fZNear;
	float				m_fZFar;
	float				m_fFOV;
	OGRenderMode		m_Mode;
};

#endif