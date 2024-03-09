/*
 * CostMapHelper.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Ikhyeon Cho
 *	 Institute: Korea Univ. ISR (Intelligent Systems & Robotics) Lab
 *       Email: tre0430@korea.ac.kr
 */

#ifndef COSTMAP_HELPER_H
#define COSTMAP_HELPER_H

#include "costmap_core/CostMap.h"

class CostMapHelper
{
public:
  static void fromOccupancyGridMap(const OccupancyGridMap& occupancy_map, CostMap& cost_map,
                                   bool use_unknown_as_free = false);
};

#endif  // COSTMAP_HELPER_H