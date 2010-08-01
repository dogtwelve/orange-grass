/*
 *  IOGModel.h
 *  OrangeGrass
 *
 *  Created by Viacheslav Bogdanov on 11.11.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef IOGMODEL_H_
#define IOGMODEL_H_

#include "IOGRenderable.h"
#include "IOGTexture.h"
#include "IOGMesh.h"


class IOGModel : public IOGRenderable
{
public:
	virtual ~IOGModel() {}

	// Update mesh animation.
	virtual void UpdateAnimation (int _ElapsedTime) = 0;

	// Get combined AABB
	virtual const IOGAabb& GetAABB () const = 0;
};


#endif