#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // remove child Edges

    for (auto it = std::begin(_childEdges); it != std::end(_childEdges); ++it)
    {
        auto manual = it->release();
        
        if(manual != nullptr)
        {
            delete manual;
        }
    }

    // remove parent Edges

    _parentEdges.clear();

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot&& chatBot)
{
    std::cout << "MoveChatbotHere [CALLED]" << std::endl;

    _chatBot = new ChatBot(std::move(chatBot));

    _chatBot->SetCurrentNode(this);

    _chatBot = &chatBot;
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    std::cout << "MoveChatbotToNewNode [CALLED]" << std::endl;

    newNode->MoveChatbotHere(std::move(*_chatBot));

    if(_chatBot != nullptr)
    {
        delete _chatBot;
        _chatBot = nullptr; // invalidate pointer at source
    }
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index) const
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}