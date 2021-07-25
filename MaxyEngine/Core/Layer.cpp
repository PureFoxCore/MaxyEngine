#include "mxpch.hpp"
#include "Core/Layer.hpp"

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