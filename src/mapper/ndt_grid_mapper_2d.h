#ifndef CSLIBS_MAPPING_NDT_GRID_MAPPER_2D_H
#define CSLIBS_MAPPING_NDT_GRID_MAPPER_2D_H

#include <mutex>
#include <atomic>
#include <condition_variable>

#include <cslibs_mapping/mapper/mapper.hpp>
#include <cslibs_mapping/maps/ndt_grid_map_2d.hpp>

namespace cslibs_mapping {
namespace mapper {
class NDTGridMapper2D : public Mapper
{
public:
    virtual inline const map_t::ConstPtr getMap() const override;

protected:
    virtual inline bool setupMap(ros::NodeHandle &nh) override;
    virtual inline bool uses(const data_t::ConstPtr &type) override;
    virtual inline void process(const data_t::ConstPtr &data) override;
    virtual inline bool saveMap() override;

private:
    maps::NDTGridMap2D::Ptr map_;
    double sampling_resolution_;
};
}
}

#endif // CSLIBS_MAPPING_NDT_GRID_MAPPER_2D_H
