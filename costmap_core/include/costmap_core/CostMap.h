/*
 * CostMap.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Ikhyeon Cho
 *	 Institute: Korea Univ. ISR (Intelligent Systems & Robotics) Lab
 *       Email: tre0430@korea.ac.kr
 */

#ifndef COSTMAP_CORE_H
#define COSTMAP_CORE_H

#include <occupancy_gridmap_core/OccupancyGridMap.h>

class CostMap : public grid_map::GridMap
{
public:
  static constexpr float COST_LETHAL = 255.0;
  static constexpr float COST_FREESPACE = 0.0;

  using Ptr = std::shared_ptr<CostMap>;

  /// @brief Costmap is composed of three layers: static, obstacle, and inflation. Each layer is default to be NaN.
  /// Static layer and Inflation layer can be initialized with the occupancy grid map. Obstacle layer is initialized
  /// with the laser sensor readings.
  CostMap();
  CostMap(const OccupancyGridMap& map);

  grid_map::GridMap::Matrix& getStaticLayer();
  grid_map::GridMap::Matrix& getObstacleLayer();
  grid_map::GridMap::Matrix& getInflationLayer();

  bool isValidAt(const grid_map::Position& position);
  bool isValidAt(const grid_map::Index& index);
  bool isEmptyAt(const grid_map::Index& index);

  bool isLethalAt(const grid_map::Index& index);
  bool isFreespaceAt(const grid_map::Index& index);

  grid_map::Index getGridIndexFrom(const grid_map::Position& position);
  grid_map::Position getPositionFrom(const grid_map::Index& index);
  float getDistance(const grid_map::Index& from, const grid_map::Index& to);

  grid_map::CircleIterator getCircleIterator(const grid_map::Index& query_index, double radius) const;
  grid_map::SubmapIterator getSquareIterator(const grid_map::Index& query_index, int search_length) const;

  // Grid Index with Cost
  struct CostComparator
  {
    grid_map::Index index;
    float cost;

    CostComparator(grid_map::Index idx, float c) : index(idx), cost(c)
    {
    }
    bool operator<(const CostComparator& grid) const
    {
      return this->cost > grid.cost;
    }
  };
};

#endif  // COSTMAP_CORE_H