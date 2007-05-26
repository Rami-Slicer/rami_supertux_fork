//  $Id$
//
//  SuperTux - "Will-O-Wisp" Badguy
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA.
#include <config.h>

#include "root.hpp"

static const float SPEED = 5;

Root::Root(const Vector& pos)
  : BadGuy(pos, "images/creatures/ghosttree/root.sprite", LAYER_OBJECTS+20),
    ypos(0), speed(-SPEED)
{
  //ypos = sprite->get_height();
}

Root::~Root()
{
}

void
Root::activate()
{
  set_pos(start_position + Vector(0, ypos));
}

void
Root::active_update(float elapsed_time)
{
  ypos += elapsed_time * speed;
  if(ypos < 0) {
    ypos = 0;
    speed = -speed;
  }
  if(speed > 0 && ypos > sprite->get_height()) {
    remove_me();
  }
  set_pos(start_position + Vector(0, ypos));
}

