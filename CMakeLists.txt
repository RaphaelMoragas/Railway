cmake_minimum_required(VERSION 3.23)
project(Railnetwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(Railnetwork main.cpp Data.cpp Data.h Menu.cpp Menu.h BasicServiceMetrics.cpp BasicServiceMetrics.h data_structures/Graph.cpp data_structures/Graph.h data_structures/VertexEdge.cpp data_structures/VertexEdge.h data_structures/MutablePriorityQueue.h)
