#include "JQuadTree.h"
#include "GameObject.h"



//------------------------------------------------------
//-------------TreeNode---------------------------------
//------------------------------------------------------

TreeNode::TreeNode(const AABB & box) : box(box)
{
}

TreeNode::~TreeNode()
{
}

void TreeNode::insert(GameObject * object)
{
}

void TreeNode::erase(GameObject * object)
{
}

void TreeNode::delSons()
{
	for (uint i = 0; i < 4; ++i)
	{
		if (childs[i] != nullptr)
		{
			childs[i]->delSons();
			RELEASE(childs[i]);
		}
	}
}


//------------------------------------------------------
//-------------JQuadTree--------------------------------
//------------------------------------------------------

JQuadTree::JQuadTree()
{
}


JQuadTree::~JQuadTree()
{
	if (rootNode != nullptr)
	{
		clear();
		RELEASE(rootNode);
	}
}

void JQuadTree::insert(GameObject* object)
{
	/*if (rootNode != nullptr && object != nullptr)
	{
		if (object->aabb.MinimalEnclosingAABB().Intersects(rootNode->box));
		{
			rootNode->insert(object);
		}
	}*/
}

void JQuadTree::erase(GameObject* object)
{
	if (rootNode != nullptr && object != nullptr)
		rootNode->erase(object);
}

void JQuadTree::setRoot(const AABB& box)
{
	if (rootNode != nullptr)
	{
		clear();
		RELEASE(rootNode);
	}
	rootNode = new TreeNode(box);
}

void JQuadTree::clear()
{
	if (rootNode != nullptr)
		rootNode->delSons();
}