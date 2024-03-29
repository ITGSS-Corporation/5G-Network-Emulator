/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 */

#pragma once


#define STATIC_MODEL 0
#define RANDOM_WALK_MODEL 1
#define RANDOM_WAYPOINT_MODEL 2
#define RANDOM_MANHATTAN_MODEL 3

#include <mobility_models/pos2d.h>
//--------------------------------------------------------------------------------------------------
// mobility_config(): struct storing all the configuration information related with the mobility
// models. 
// Input: 
//      _type: id of the desired mobility model for the current UE. 
//      _x,_y: initial position only used if _random_init is set to false.
//      _random_init: wether to randomly initialized or not
//      _speed: target speed of the UEs.
//      _speed_var: size of the white noise to be applied in each timestep to the target speed.
//      _max_distance: max. distance of the UE to the gNB. 
//      _time_target: target time used in some of the implemented models, such as random walk model.
//      _time_target_var: size of the white noise to be applied in each timestep to the target time.
//--------------------------------------------------------------------------------------------------
struct mobility_config
{
    mobility_config(){}
    mobility_config(int _type, float _x, float _y, bool _random_init, float _speed, float _speed_var,
                    float _max_distance, float _time_target, 
                    float _time_target_var):
                    init_pos(_x, _y)
                    {
                        type = _type; 
                        random_init = _random_init; 
                        speed = _speed; 
                        speed_var = _speed_var; 
                        max_speed = speed + speed_var; 
                        max_distance = _max_distance; 
                        time_target = _time_target; 
                        time_target_var = _time_target_var; 
                    }
    int type; 
    pos2d init_pos; 
    bool random_init; 
    float speed; 
    float speed_var; 
    float max_speed; 
    float max_distance; 
    float time_target; 
    float time_target_var; 
    bool random_v = true; 
    float get_max_speed(){ return speed + speed_var;}
};