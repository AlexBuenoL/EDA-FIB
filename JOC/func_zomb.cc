//------------------------------------------------------------------------------------------------
          //Down, DR, Right, RU, Up, UL, Left, LD
          
          if (distZombie == 2) {
              if (PI.pos_zombie == pUV+DR) {
                  Pos z1 = pUV+Up;
                  Pos z2 = pUV+Left;
                  if (pos_ok(z1) and cell(z1).type != Waste) move(id, Up);
                  else if (pos_ok(z2) and cell(z2).type != Waste) move(id, Left);
                  
              } else if (PI.pos_zombie == pUV+RU) {
                  Pos z1 = pUV+Down;
                  Pos z2 = pUV+Left;
                  if (pos_ok(z1) and cell(z1).type != Waste) move(id, Down);
                  else if (pos_ok(z2) and cell(z2).type != Waste) move(id, Left);
                
              } else if (PI.pos_zombie == pUV+UL) {
                  Pos z1 = pUV+Right;
                  Pos z2 = pUV+Down;
                  if (pos_ok(z1) and cell(z1).type != Waste) move(id, Right);
                  else if (pos_ok(z2) and cell(z2).type != Waste) move(id, Down);
                  
              } else if (PI.pos_zombie == pUV+LD) {
                  Pos z1 = pUV+Up;
                  Pos z2 = pUV+Right;
                  if (pos_ok(z1) and cell(z1).type != Waste) move(id, Up);
                  else if (pos_ok(z2) and cell(z2).type != Waste) move(id, Right);
              }
          }
              
//------------------------------------------------------------------------------------------------
