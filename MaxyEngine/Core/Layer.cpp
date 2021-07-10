#include "mxpch.h"
#include "Core/Layer.h"

namespace Maxy
{
    Layer::Layer(const std::string &debugName)
        : m_DebugName(debugName)
    {
    }

    Layer::~Layer()
    {
    }
}