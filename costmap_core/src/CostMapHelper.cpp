/*
 * CostMapHelper.cpp
 *
 *  Created on: Feb 29, 2024
 *      Author: Ikhyeon Cho
 *	 Institute: Korea Univ. ISR (Intelligent Systems & Robotics) Lab
 *       Email: tre0430@korea.ac.kr
 */

#include "costmap_core/CostMapHelper.h"

void CostMapHelper::fromOccupancyGridMap(const OccupancyGridMap& occupancy_map, CostMap& cost_map,
                                         bool use_unknown_as_free)
{
  const auto& occupancy_layer = occupancy_map.getOccupancyLayer();
  auto& static_cost_layer = cost_map.getStaticLayer();

  cost_map.setGeometry(grid_map::Length(occupancy_map.getLength()), occupancy_map.getResolution());
  static_cost_layer = occupancy_layer * CostMap::COST_LETHAL;
  
  if (use_unknown_as_free)
  {
    static_cost_layer = static_cost_layer.array().isNaN().select(CostMap::COST_FREESPACE, static_cost_layer);
  }
  else
  {
    static_cost_layer = static_cost_layer.array().isNaN().select(CostMap::COST_LETHAL, static_cost_layer);
  }
}