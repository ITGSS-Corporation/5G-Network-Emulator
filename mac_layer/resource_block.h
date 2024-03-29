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

#ifndef RESOURCE_BLOCK_H
#define RESOURCE_BLOCK_H

#include <string>
#include <algorithm>

#include <mac_layer/metric_handler.h>
#include <ue/ue.h>

// Logging

#include "utils/logging/log_handler.h"

// TX MODE
#ifndef T_DL
#define T_DL 0
#endif
#ifndef T_UL
#define T_UL 1
#endif

//--------------------------------------------------------------------------------------------------
// rb(): class which is in charge of assigning the best UE to the current RB/RBG. This class gets the
// estimated metric for each UE assigning the one with highest metric. It also estimates the number 
// of bits granted to the assigned users according to the selected duplexing type.
// Input: 
//      * _t: time index of the current RB/RBG within the resource allocation grid.
//      * _f: frequency index of the current RB/RBG within the resource allocation grid.
//      * _tx: transmission direction of current RB/RBG.
//      * _mimo_layers: number of available MIMO Layers.
//      * _n_sc: total number of subcarriers.
//      * *_ue_list: pointer to the list of connected UEs.
//      * _verbosity: enable/disable verbosity
//      * _logger: pointer to instance of the logger class, used for data logging.
//--------------------------------------------------------------------------------------------------
class rb
{
public: 
    rb(int _t, int _f, int _tx, int _mimo_layers,  int _n_sc, std::vector<ue> *_ue_list, int _verbosity = 0, log_handler * _logger = nullptr); 
private: 
    bool store_hist; 
    int mimo_layers; 
    int t; 
    int f; 
    int tx; 
    int n_sc; 
    max_metric_handler max_metric;    
    std::vector<ue> *ue_list; 
    float current_t;
    bool log; 

private: 
    void reset_metric();
    bool check_ue_assignment();
public: 
    void estimate_params(int syms, float current_t);
    // Handle Packets
    float handle_packet(int syms);
    log_handler * logger;
private: 
    int verbosity = 0; 
};

#endif