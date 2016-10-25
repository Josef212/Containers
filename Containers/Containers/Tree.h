#ifndef __TREE__
#define __TREE__

#include <list>

/** Helper class to contain tree data and tree hierarchy. */
template<class TYPE>
class treeNode
{
public:
	treeNode(TYPE _data) : data(_data), dad(nullptr)
	{
	}

	treeNode(TYPE _data, treeNode* _dad) : data(_data), dad(_dad)
	{
		if (_dad)
			_dad->addSon(this);
	}

	void addSon(treeNode* node)
	{
		if (node)
		{
			childs.push_back(node);
			node->parent = this;
		}
	}

	treeNode* addSon(TYPE _data)
	{
		treeNode* ret = nullptr;
		ret = new treeNode(_data, this);

		return ret;
	}

	void delSons()
	{
		for (std::list<treeNode*>::iterator it = childs.begin(); it != chil.end(); ++it)
		{
			(*it)->delSons();
			RELEASE((*it));
		}
	}

	bool delSon(treeNode* node)
	{
		bool ret = false;

		if (node != nullptr)
		{
			for (std::list<treeNode*>::iterator it = childs.begin(); it != chil.end(); ++it)
			{
				if ((*it) == node)
				{
					node->delSons();
					childs->erase(it);
					RELEASE((*it));
					ret = true;
				}
			}
		}

		return ret;
	}

	~treeNode()
	{
	}



private:
	TYPE data;
	treeNode* parent = nullptr;
	std::list<treeNode*> childs;
}; // treeNode


//------------------------------------------------------------------------------


template<class TYPE>
class Tree
{
public:
	Tree(const TYPE& data)
	{
		root = new treeNode(data);
	}

	~Tree()
	{
		clear();
		RELEASE(root);
	}

	treeNode* addNode(TYPE& data, treeNode* dad = nullptr)
	{
		treeNode* ret = nullptr;

		if (dad != nullptr)
			ret = dad->addSon(data);
		else
			ret = root->addSon(data);

		return ret;
	}



	void clear()
	{
		if (root)
			root->delSons();
	}

private:
	treeNode<TYPE>* root = nullptr;

}; // Tree

#endif // !__TREE__