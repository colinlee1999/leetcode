// suffer tree.cpp : 定义控制台应用程序的入口点。   
//copyright@ 2011 July && 匿名   

//1、参考了他人的程序，但不知道原作者是谁。   
//如果你知道，请立马联系我，一定把原作者的大名署上，谢谢。   
//2、主函数没有写全了，读者视需要自己补上吧。   

#include "stdafx.h"   
#ifndef __SUFFIXTREE_H   
#define __SUFFIXTREE_H   
#include <list>   
#include <vector>   
#include <iostream>   
using namespace std;
using std::list;
using std::vector;

//对于叶节点,通过m_nActiveLen和m_nEdgeLabelEndPos可以得到节点对应的字符串.对于分支节点,也是如此.   
struct tagSuffixNode
{
public:
	tagSuffixNode* m_tpChild;   //子节点,如果为0,说明是叶子节点   
	tagSuffixNode* m_tpParent;  //父节点,根节点的父节点为0   
	tagSuffixNode* m_tpLeftSibling;     //左兄弟   
	tagSuffixNode* m_tpRightSibling;    //右兄弟   
	tagSuffixNode* m_tpMostRightChild;  //最右子节点   
	tagSuffixNode* m_tpSuffixLink;      //指向当前节点表示的子串的最大后缀所对应的分支节点   

	int m_nActiveLen;   //节点代表的字符串的长度.       
	int m_nEdgeLabelStartPos;   //入边开始字符的下标.对于分支节点,只是用来表示边对应的字符串是什么,并不表示其在子孙叶节点表示的串中对应位置的字符在整个串中的下标.   
	int m_nEdgeLabelEndPos;     //入边结束字符的下标   
	bool m_bIsLeaf;     //是否是叶节点   

	char m_cIndex;  //test   

public:
	//全部初始化为0   
	void init()
	{
		m_tpChild = 0;
		m_tpParent = 0;
		m_tpLeftSibling = 0;
		m_tpRightSibling = 0;
		m_tpMostRightChild = 0;
		m_tpSuffixLink = 0;

		m_nEdgeLabelStartPos = 0;
		m_nEdgeLabelEndPos = 0;

		m_nActiveLen = 0;
		m_bIsLeaf = true;
	}
};

class CSuffixTree
{
public:
	CSuffixTree(char *str);
	~CSuffixTree();
	void deleteTree();
	void construct();
	void reset(char *str);
	int search(char *str);
	tagSuffixNode* getTree();
	void printTree();
	void test();
private:
	tagSuffixNode* __allocNode();
	tagSuffixNode* __findChildBeginWithChar(tagSuffixNode* node, char c);

	void __printHelper(tagSuffixNode* node, int level);
private:
	int m_nActiveLen;
	int m_nStrLen; //字符串长度   
	tagSuffixNode* m_tpRoot; //根节点   
	tagSuffixNode* m_tpActiveNode; //活动节点   
	char *m_cpInternalStr; //字符串内存存储   

	list<tagSuffixNode*> m_tagNodeList; //保存分配的节点的指针   
	vector<tagSuffixNode*> m_tagFromNodeVec; //保存还未确定后缀指针的分支节点的指针，用于判定suffix link   
	vector<tagSuffixNode*> m_tagToNodeVec; //保存所有分支节点   
#ifdef DEBUG   
	char m_cIndex;
#endif   
};

#endif //    

//#include "suffixtree.h"   
#include <list>   
#include <vector>   
#include <cstring>   
#include <cassert>   
#include <cstdio>   
using namespace std;

CSuffixTree::CSuffixTree(char *str)
	:m_nActiveLen(0),
	m_tpRoot(0),
	m_tpActiveNode(0)
{
	m_nStrLen = strlen(str) + 1;
	m_cpInternalStr = new char[m_nStrLen + 1];

	sprintf(m_cpInternalStr, "%s#", str);
#ifdef DEBUG       
	m_cIndex = 'A';
#endif       
}

CSuffixTree::~CSuffixTree()
{
	deleteTree();
	delete[] m_cpInternalStr;
}

void CSuffixTree::deleteTree()
{
	list<tagSuffixNode*>::iterator iter = m_tagNodeList.begin();
	for (; iter != m_tagNodeList.end(); ++iter)
	{
		delete *iter;
	}

	m_tagNodeList.clear();
}

void CSuffixTree::reset(char *str)
{
	deleteTree();

	int tmp = strlen(str);
	if (tmp + 1 > m_nStrLen)
	{
		m_nStrLen = tmp + 1;
		delete[] m_cpInternalStr;
		m_cpInternalStr = new char[m_nStrLen + 1];
	}
	else
	{
		m_nStrLen = tmp + 1;
	}
	sprintf(m_cpInternalStr, "%s#", str);

	m_nActiveLen = 0;
	m_nStrLen = 0;
	m_tpActiveNode = 0;
	m_tpRoot = 0;

	m_tagFromNodeVec.clear();
	//reconstruct tree for new string   
	construct();
}


//suffixTree之构造   
void CSuffixTree::construct()
{
	m_tpRoot = __allocNode();
	if (m_tpRoot == 0)
	{
#ifdef DEBUG   
		printf("__allocNode error!\n");
#endif   
		return;
	}
	m_nActiveLen = 0;
	m_tpRoot->m_nActiveLen = 0;
	//initial active node   
	m_tpActiveNode = m_tpRoot;

	m_tagToNodeVec.push_back(m_tpRoot);

	for (int i = 0; i < m_nStrLen; i++)
	{
#ifdef DEBUG   
		printf("\ninsert %s\n", &(m_cpInternalStr[i]));
		printf("active node:[%c]\n", m_tpActiveNode->m_cIndex);
#endif   
		//判断是否有后继节点   
		if (m_tpActiveNode->m_tpSuffixLink != 0)
		{
			m_tpActiveNode = m_tpActiveNode->m_tpSuffixLink;
			m_nActiveLen--;
		}
		int pos = i;

#ifdef DEBUG           
		printf("new active node:[%c]\n", m_tpActiveNode->m_cIndex);
		printf("pos:%d\n", pos);
		printf("active length:%d\n", m_nActiveLen);
#endif           

		while (true)
		{
			//查找以当前后缀串的开始字符开始的子节点   
			tagSuffixNode* node = __findChildBeginWithChar(m_tpActiveNode, m_cpInternalStr[i + m_nActiveLen]);
			//未找到以suffix[i]的开始字符开头的节点   
			if (node == 0)
			{
#ifdef DEBUG   
				printf("__findChildBeginWithChar null\n");
#endif                   
				tagSuffixNode* child = __allocNode();

				//设置开始、结束位置的下标   
				child->m_nEdgeLabelStartPos = pos;
				child->m_nEdgeLabelEndPos = m_nStrLen - 1;
				//设置叶节点代表的后缀串的长度   
				child->m_nActiveLen = m_nStrLen - i;
				//设置父节点   
				child->m_tpParent = m_tpActiveNode;
				if (m_tpActiveNode->m_tpChild == 0)
				{
					m_tpActiveNode->m_tpChild = child;
					m_tpActiveNode->m_tpMostRightChild = child;
				}
				else
				{
					m_tpActiveNode->m_tpMostRightChild->m_tpRightSibling = child;
					child->m_tpLeftSibling = m_tpActiveNode->m_tpMostRightChild;
					m_tpActiveNode->m_tpMostRightChild = child;
				}

				break;
			}
			else
			{
#ifdef DEBUG   
				printf("__findChildBeginWithChar ok\n");
				printf("node start:%d\n", node->m_nEdgeLabelStartPos);
				printf("node end:%d\n", node->m_nEdgeLabelEndPos);
				printf("node index:%c\n", node->m_cIndex);
#endif   
				//TODO   
				//确定 m_nMinDistance   
				int edgeStart = node->m_nEdgeLabelStartPos;
				int strStart = i + m_nActiveLen;
				bool split = false;

				for (; edgeStart <= node->m_nEdgeLabelEndPos; edgeStart++, strStart++)
				{
					if (m_cpInternalStr[edgeStart] != m_cpInternalStr[strStart])
					{
						split = true;
						break;
					}
				}
				if (!split)
				{
					m_tpActiveNode = node;
					m_nActiveLen += node->m_nEdgeLabelEndPos - node->m_nEdgeLabelStartPos + 1;
					pos += node->m_nEdgeLabelEndPos - node->m_nEdgeLabelStartPos + 1;
					continue;
				}
				else
				{
					tagSuffixNode* parent = node->m_tpParent;
					//new branch node   
					tagSuffixNode* branch = __allocNode();
					branch->m_bIsLeaf = false;
					branch->m_nEdgeLabelStartPos = node->m_nEdgeLabelStartPos;
					branch->m_nEdgeLabelEndPos = edgeStart - 1;
					branch->m_nActiveLen = parent->m_nActiveLen + (branch->m_nEdgeLabelEndPos - branch->m_nEdgeLabelStartPos + 1);
					//original node   
					node->m_nEdgeLabelStartPos = edgeStart;

					tagSuffixNode* info = __allocNode();
					info->m_nEdgeLabelStartPos = strStart;
					info->m_nEdgeLabelEndPos = m_nStrLen - 1;
					info->m_nActiveLen = branch->m_nActiveLen + (info->m_nEdgeLabelEndPos - info->m_nEdgeLabelStartPos + 1);

					branch->m_tpParent = parent;
					branch->m_tpRightSibling = parent->m_tpChild;
					parent->m_tpChild->m_tpLeftSibling = branch;
					parent->m_tpChild = branch;

					node->m_tpLeftSibling->m_tpRightSibling = node->m_tpRightSibling;
					if (node->m_tpRightSibling != 0)
					{
						node->m_tpRightSibling->m_tpLeftSibling = node->m_tpLeftSibling;
					}
					else
					{
						parent->m_tpMostRightChild = node->m_tpLeftSibling;
					}

					branch->m_tpChild = info;
					branch->m_tpMostRightChild = node;

					info->m_tpRightSibling = node;
					info->m_tpParent = branch;

					node->m_tpParent = branch;
					node->m_tpLeftSibling = info;
					node->m_tpRightSibling = 0;


					//设置节点的suffix link   

					bool setSuffix = false;
					vector<tagSuffixNode*>::iterator iter = m_tagToNodeVec.begin();
					for (; iter != m_tagToNodeVec.end(); ++iter)
					{
						tagSuffixNode* tmp = *iter;
						if (strncmp(&(m_cpInternalStr[branch->m_nEdgeLabelEndPos - branch->m_nActiveLen + 2]), &(m_cpInternalStr[tmp->m_nEdgeLabelEndPos - tmp->m_nActiveLen + 1]), branch->m_nActiveLen - 1) == 0)
						{
							branch->m_tpSuffixLink = tmp;
							setSuffix = true;
							break;
#ifdef DEBUG   
							printf("branch[%c] suffix_link is branch[%c]\n", tmp->m_cIndex, branch->m_cIndex);
#endif                                   
						}
					}
					m_tagToNodeVec.push_back(branch);

					vector<tagSuffixNode*>::iterator iter2 = m_tagFromNodeVec.begin();
					for (; iter2 != m_tagFromNodeVec.end(); ++iter2)
					{
						tagSuffixNode* tmp = *iter2;
						//找到后缀节点，结束循环   
						if (strncmp(&(m_cpInternalStr[tmp->m_nEdgeLabelEndPos - tmp->m_nActiveLen + 2]), &(m_cpInternalStr[branch->m_nEdgeLabelEndPos - branch->m_nActiveLen + 1]), tmp->m_nActiveLen - 1) == 0)
						{
							tmp->m_tpSuffixLink = branch;
							m_tagFromNodeVec.erase(iter2);
#ifdef DEBUG   
							printf("branch[%c] suffix_link is branch[%c]\n", tmp->m_cIndex, branch->m_cIndex);
#endif   
							break;
						}
					}

					if (!setSuffix)
					{
						m_tagFromNodeVec.push_back(branch);
					}

					//已经将新的后缀字符串插入到树中，这时可以结束while了。   
					break;
				}
			}
		}
		//test   
#ifdef DEBUG   
		printf("print\n");
		printTree();
#endif           
	}
}


//查询   
int CSuffixTree::search(char *str)
{
	if (str == 0)
		return -1;
	//TODO   
	//添加处理过程   

	int len = strlen(str);

	tagSuffixNode* node = 0;
	tagSuffixNode* cur = m_tpRoot;
	for (int i = 0; i < len; )
	{
		node = __findChildBeginWithChar(cur, str[i]);
		if (node == 0)
		{
			break;
		}
		else
		{
			int edgeLen = node->m_nEdgeLabelEndPos - node->m_nEdgeLabelStartPos + 1;
			int remain = len - i;
			if (remain <= edgeLen)
			{
				if (strncmp(&(str[i]), &(m_cpInternalStr[node->m_nEdgeLabelStartPos]), remain) != 0)
				{
					return -1;
				}
				else
				{
					return node->m_nEdgeLabelEndPos - node->m_nActiveLen + 1;
				}
			}
			else
			{
				if (strncmp(&(str[i]), &(m_cpInternalStr[node->m_nEdgeLabelStartPos]), edgeLen) != 0)
				{
					return -1;
				}
				else
				{
					i += edgeLen;
					cur = node;
				}
			}
		}
	}
	return -1;
}

tagSuffixNode* CSuffixTree::__allocNode()
{
	tagSuffixNode* node = new tagSuffixNode;

	m_tagNodeList.push_back(node);

	node->init();
#ifdef DEBUG       
	node->m_cIndex = m_cIndex;
	m_cIndex++;
#endif       
	return node;
}

tagSuffixNode* CSuffixTree::__findChildBeginWithChar(tagSuffixNode* node, char c)
{
	assert(node != 0);

	tagSuffixNode* child = node->m_tpChild;
	while (child != 0)
	{
		if (m_cpInternalStr[child->m_nEdgeLabelStartPos] == c)
			return child;

		child = child->m_tpRightSibling;
	}

	return 0;
}

void CSuffixTree::test()
{
	//printf("%s\n", m_cpInternalStr);   
	printTree();
}

void CSuffixTree::printTree()
{
#ifdef DEBUG   
	printf("[A]\n");
#endif   
	__printHelper(m_tpRoot, 0);
}

void CSuffixTree::__printHelper(tagSuffixNode* node, int level)
{
	int start = node->m_nEdgeLabelStartPos;
	int end = node->m_nEdgeLabelEndPos;
	tagSuffixNode* child = node->m_tpChild;
	if (level > 0)
	{
		for (int i = 0; i < level; i++)
		{
			printf(" |");
		}
		printf(" + ");
		for (int j = start; j <= end; j++)
		{
			printf("%c", m_cpInternalStr[j]);
		}
#ifdef DEBUG           
		printf("[%c]", node->m_cIndex);
		//         printf("[%d:%d:%d]", node->m_nEdgeLabelStartPos, node->m_nEdgeLabelEndPos, node->m_nActiveLen);   
#endif           
		printf("\n");
	}

	while (child != 0)
	{
		__printHelper(child, level + 1);
		child = child->m_tpRightSibling;
	}
}

int main()
{
	cout << "hello suffixtree" << endl;
	system("pause");
	return 0;
}