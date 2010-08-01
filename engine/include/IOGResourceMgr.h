/*
 *  IOGResourceMgr.h
 *  OrangeGrass
 *
 *  Created by Viacheslav Bogdanov on 11.11.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef IOGRESOURCEMGR_H_
#define IOGRESOURCEMGR_H_

#include "IOGTexture.h"
#include "IOGMesh.h"
#include "IOGModel.h"
#include "IOGTerrain.h"


struct IOGResourceInfo
{
	char	m_pResource[256];
	char	m_pResourceIcon[256];
	char	m_pResourceGroup[256];
};


class IOGResourceMgr
{
public:
	virtual ~IOGResourceMgr () {}
		
	// load from file.
	virtual bool Init (const char* _pResourceFile) = 0;

    // get resource path
    virtual const char* GetResourcePath () const = 0;

	// load next resource.
	virtual bool LoadNext (IOGResourceInfo& _resInfo) = 0;
		
	// get texture.
	virtual IOGTexture* GetTexture (const char* _pAlias) = 0;
		
	// get mesh.
	virtual IOGMesh* GetMesh (const char* _pAlias) = 0;

	// get model.
	virtual IOGModel* GetModel (const char* _pAlias) = 0;

	// get terrain.
	virtual IOGTerrain* GetTerrain (const char* _pAlias) = 0;
};

#endif
