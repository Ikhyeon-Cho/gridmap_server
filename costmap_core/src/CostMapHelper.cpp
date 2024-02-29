/*
 * CostMapHelper.cpp
 *
 *  Created on: Feb 29, 2024
 *      Author: Ikhyeon Cho
 *	 Institute: Korea Univ. ISR (Intelligent Systems & Robotics) Lab
 *       Email: tre0430@korea.ac.kr
 */

#include "costmap_core/CostMapHelper.h"

void CostMapHelper::fromOccupancyGridMap(const OccupancyGridMap& occupancy_map, CostMap& cost_map)
{
  cost_map.setGeometry(grid_map::Length(occupancy_map.getLength()), occupancy_map.getResolution());
  cost_map.getStaticLayer() = occupancy_map.getOccupancyLayer() * CostMap::COST_LETHAL;
}