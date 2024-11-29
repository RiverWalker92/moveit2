
/*********************************************************************
 * All MoveIt 2 headers have been updated to use the .hpp extension.
 *
 * .h headers are now autogenerated via create_deprecated_headers.py,
 * and will import the corresponding .hpp with a deprecation warning.
 *
 * imports via .h files may be removed in future releases, so please
 * modify your imports to use the corresponding .hpp imports.
 *
 * See https://github.com/moveit/moveit2/pull/3113 for extra details.
 *********************************************************************/
/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2024, PickNik Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of PickNik Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Paul Gesel
Description: applies smoothing by limiting the acceleration between consecutive commands.
The purpose of the plugin is to prevent the robot's acceleration limits from being violated by instantaneous changes
to the servo command topics.

 In the diagrams below, the c-v lines show the displacement that will occur given the current velocity. The t-c lines
 shows the displacement between the current position and the desired position. The dashed lines shows the maximum
 possible displacements that are within the acceleration limits. The v-t lines shows the acceleration commands that
 will be used by this acceleration-limiting plugin. The x point shows the position that will be used for each scenario.

Scenario A: The desired position is within the acceleration limits. The next commanded point will be exactly the
desired point.
     ________
    |        |
c --|-----xt |
 \__|__ v    |
    |________|

Scenario B: The line between the current position and the desired position intersects the acceleration limits, but the
reference position is not within the bounds. The next commanded point will be the point on the displacement line that
is closest to the reference.
     ________
    |        |
c --|--------x------t
 \__|__ v    |
    |________|

Scenario C: Neither the displacement line intersects the acceleration limits nor does the reference point lie within
the limits. In this case, the next commanded point will be the one that minimizes the robot's velocity while
maintaining its direction.
           ________
          |        |
c --------x--- v   |
 \        |        |
  \       |________|
   t
 */

#pragma once
#pragma message(".h header is obsolete. Please use the .hpp header instead.")
#include <moveit/online_signal_smoothing/acceleration_filter.hpp>