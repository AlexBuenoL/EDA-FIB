#include "Player.hh"
#include <queue>
#include <climits>
#define PLAYER_NAME AlixV2

struct PLAYER_NAME : public Player {

  //Factory: returns a new instance of this class.
  //Do not modify this function.
  static Player* factory () {
    return new PLAYER_NAME;
  }
  
  struct PosImportants {
      Pos pos_enem;
      Pos pos_food;
      Pos pos_zombie;
      Pos pos_dead;
  };
  
  struct Info_obj {
      int id;
      Pos pos_obj;
      int dist_obj;
      Dir dir_obj;
  };
  
  //Types and attributes for your player can be defined here.
  const vector<Dir> dirs = {Up,Down,Left,Right};
  
  // BFS que retorna un struct amb la posició mes proopera de: enemic, zombie, food
  PosImportants BFS_cerca_objectiu(Pos& pUV) {
      
      vector< vector<bool> > visited(60, vector<bool>(60, false));
      visited[pUV.i][pUV.j] = true;
      
      queue<Pos> Q;
      Q.push(pUV);
      PosImportants PI;
      bool enem = false, food = false, zombie = false, dead = false;
      bool end = false;
      
      while (not Q.empty() and not end) {
          
          Pos p = Q.front();
          Q.pop();
          
          if (pos_ok(p) and cell(p).type != Waste) {
              
              if (cell(p).id != -1 and unit(cell(p).id).type == Alive and unit(cell(p).id).player != me() and not enem) {
                  PI.pos_enem = p;
                  enem = true;
                  
              } else if (cell(p).id != -1 and unit(cell(p).id).type == Zombie and not zombie) {
                  PI.pos_zombie = p;
                  zombie = true;
                  
              } else if (cell(p).food and not food) {
                  PI.pos_food = p;
                  food = true;
                  
              } else if (cell(p).id != -1 and unit(cell(p).id).type == Dead and not dead) {
                  PI.pos_dead = p;
                  dead = true;
              }
              
              if (enem and zombie and food and dead) end = true;
          }
          
          Pos p1 = {p.i+1,p.j};
          if (pos_ok(p1) and cell(p1).type != Waste and not visited[p.i+1][p.j]) {
              Q.push(p1);
              visited[p.i+1][p.j] = true;
          }
          
          Pos p3 = {p.i,p.j+1};
          if (pos_ok(p3) and cell(p3).type != Waste and not visited[p.i][p.j+1]) {
              Q.push(p3);
              visited[p.i][p.j+1] = true;
          }
          
          Pos p5 = {p.i-1,p.j};
          if (pos_ok(p5) and cell(p5).type != Waste and not visited[p.i-1][p.j]) {
              Q.push(p5);
              visited[p.i-1][p.j] = true;
          }
          
          Pos p7 = {p.i, p.j-1};
          if (pos_ok(p7) and cell(p7).type != Waste and not visited[p.i][p.j-1]) {
              Q.push(p7);
              visited[p.i][p.j-1] = true;
          }
          
          Pos p2 = {p.i+1,p.j+1};
          if (pos_ok(p2) and cell(p2).type != Waste and not visited[p.i+1][p.j+1]) {
              Q.push(p2);
              visited[p.i+1][p.j+1] = true;
          }
          
          Pos p4 = {p.i-1,p.j+1};
          if (pos_ok(p4) and cell(p4).type != Waste and not visited[p.i-1][p.j+1]) {
              Q.push(p4);
              visited[p.i-1][p.j+1] = true;
          }
          
          Pos p6 = {p.i-1,p.j-1};
          if (pos_ok(p6) and cell(p6).type != Waste and not visited[p.i-1][p.j-1]) {
              Q.push(p6);
              visited[p.i-1][p.j-1] = true;
          }
          
          Pos p8 = {p.i+1, p.j-1};
          if (pos_ok(p8) and cell(p8).type != Waste and not visited[p.i+1][p.j-1]) {
              Q.push(p8);
              visited[p.i+1][p.j-1] = true;
          }
      }
      
      return PI;
  }
  
  // Calcula la distancia que hi ha entre pUV i l'objectiu comencant per la direccio 'dir'
  int BFS_minim_distance(Pos& np, Pos& obj) {
      
      queue<Pos> QP;
      vector<vector<int> > dist(60, vector<int>(60, -1));
      vector< vector<bool> > visited(60, vector<bool>(60, false));
      visited[np.i][np.j] = true;
      
      QP.push(np);
      dist[np.i][np.j] = 0;
      
      while (not QP.empty()) {
          
          Pos p = QP.front();
          QP.pop();
          
          if (p == obj) return dist[p.i][p.j];
          visited[p.i][p.j] = true;
          
          Pos p1 = {p.i+1,p.j};
          if (pos_ok(p1) and cell(p1).type != Waste and not visited[p.i+1][p.j]) {
              QP.push(p1);
              dist[p.i+1][p.j] = dist[p.i][p.j] + 1;
              visited[p.i+1][p.j] = true;
          }
          
          Pos p2 = {p.i-1,p.j};
          if (pos_ok(p2) and cell(p2).type != Waste and not visited[p.i-1][p.j]) {
              QP.push(p2);
              dist[p.i-1][p.j] = dist[p.i][p.j] + 1;
              visited[p.i-1][p.j] = true;
          }
          
          Pos p3 = {p.i,p.j+1};
          if (pos_ok(p3) and cell(p3).type != Waste and not visited[p.i][p.j+1]) {
              QP.push(p3);
              dist[p.i][p.j+1] = dist[p.i][p.j] + 1;
              visited[p.i][p.j+1] = true;
          }
          
          Pos p4 = {p.i, p.j-1};
          if (pos_ok(p4) and cell(p4).type != Waste and not visited[p.i][p.j-1]) {
              QP.push(p4);
              dist[p.i][p.j-1] = dist[p.i][p.j] + 1;
              visited[p.i][p.j-1] = true;
          }
      }
      return INT_MAX;
  }
  
  bool repeated(Pos obj, const vector<Info_obj>& v) {
      int n = v.size();
      for (int i = 0; i < n; ++i) {
          if (obj == v[i].pos_obj) return true;
      }
      return false;
  }
  
  
  //Play method, invoked once per each round.
  virtual void play () {
      
      double st = status(me());
      if (st > 0.9) return;
      
      vector<int> UnitatsVives = alive_units(me());
      vector<Info_obj> v_objs;
      
      for (int id : UnitatsVives) {
          
          Pos pUV = unit(id).pos;
          
          
          
          // PI: struct amb les posicions mes properes de: enemic, zombie, food
          PosImportants PI = BFS_cerca_objectiu(pUV);
          
          // Es calcula les distancia mínima al enemic mes proxim
          Dir dirEnem = Right;
          int distEnem = INT_MAX;
          for (auto d1 : dirs) {
              Pos np1 = pUV + d1;
              if (pos_ok(np1) and cell(np1).type != Waste and cell(np1).id == -1) {
                  int dist1 = BFS_minim_distance(np1, PI.pos_enem)+1;
                  if (dist1 < distEnem) {
                      distEnem = dist1;
                      dirEnem = d1;
                  }
              }
              
          }
          
          // Es calcula les distancia mínima al zombie mes proxim
          Dir dirZombie = Left;
          int distZombie = INT_MAX;
          for (auto d2 : dirs) {
              Pos np2 = pUV + d2;
              if (pos_ok(np2) and cell(np2).type != Waste and cell(np2).id == -1) {
                  int dist2 = BFS_minim_distance(np2, PI.pos_zombie)+1;
                  if (dist2 < distZombie) {
                      distZombie = dist2;
                      dirZombie = d2;
                  }
              }
              
          }
          
          // Es calcula les distancia mínima al menjar mes proxim
          Dir dirFood = Up;
          int distFood = INT_MAX;
          for (auto d3 : dirs) {
              Pos np3 = pUV + d3;
              if (pos_ok(np3) and cell(np3).type != Waste and cell(np3).id == -1) {
                  int dist3 = BFS_minim_distance(np3, PI.pos_food)+1;
                  if (dist3 < distFood) {
                      distFood = dist3;
                      dirFood = d3;
                  }
              }
              
          }
          
          // Es calcula la distancia mínima a la unitat morta mes pròxima
          Dir dirDead = Right;
          int distDead = INT_MAX;
          for (auto d4 : dirs) {
              Pos np4 = pUV + d4;
              if (pos_ok(np4) and cell(np4).type != Waste and cell(np4).id == -1) {
                  int dist4 = BFS_minim_distance(np4, PI.pos_dead)+1;
                  if (dist4 < distDead) {
                      distDead = dist4;
                      dirDead = d4;
                  }
              }
              
          }
          
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
          
          // for per comprovar al voltant
          for (auto d : dirs) {
              Pos p = pUV + d;
              if (pos_ok(p) and cell(p).type != Waste and cell(p).id != -1 and unit(cell(p).id).type != Dead 
                  and unit(cell(p).id).player != me()) {
                  //move(id,d);
                  Info_obj IO;
                  IO.id = id;
                  IO.pos_obj = p;
                  IO.dist_obj = 1;
                  IO.dir_obj = d;
                  v_objs.push_back(IO);
                  break;
              }
          }
          for (auto d : dirs) {
              Pos p = pUV + d;
              if (pos_ok(p) and cell(p).type != Waste and cell(p).food) {
                  //move(id,d);
                  Info_obj IO;
                  IO.id = id;
                  IO.pos_obj = p;
                  IO.dist_obj = 1;
                  IO.dir_obj = d;
                  v_objs.push_back(IO);
                  break;
              }
          }
          
          for (auto d : dirs) {
              Pos p = pUV + d;
              if (pos_ok(p) and cell(p).type != Waste and cell(p).id != -1 and unit(cell(p).id).type == Dead and unit(cell(p).id).rounds_for_zombie <= 5) {
                  //move(id,d);
                  Info_obj IO;
                  IO.id = id;
                  IO.pos_obj = p;
                  IO.dist_obj = 1;
                  IO.dir_obj = d;
                  v_objs.push_back(IO);
              }
          }
          
          // Tenim pos_enem, dirEnem, pos_zombie, dirZombie, pos_food, dirFood, pos_dead, dirDead
          // queden 4: 1, 2, 3, i a la 4a es transforma en zombie
          
          // Si el que tinc mes aprop es una morta
          if (distDead <= distEnem and distDead <= distZombie and distDead <= distFood and distDead <= unit(cell(PI.pos_dead).id).rounds_for_zombie 
              and not repeated(PI.pos_dead, v_objs)) {
              //move(id, dirDead);
              Info_obj IO;
              IO.id = id;
              IO.pos_obj = PI.pos_dead;
              IO.dist_obj = distDead;
              IO.dir_obj = dirDead;
              v_objs.push_back(IO);
          }
          else {
              
              if (distFood <= distEnem and distFood <= distZombie and not repeated(PI.pos_food, v_objs)) {
                  //move(id, dirFood);
                  Info_obj IO;
                  IO.id = id;
                  IO.pos_obj = PI.pos_food;
                  IO.dist_obj = distFood;
                  IO.dir_obj = dirFood;
                  v_objs.push_back(IO);
              }
          
              // Si el menjar no és el que està més a prop
              else {
              
                  if (distZombie == 2) {
                      if (distFood - distEnem <= 5 and not repeated(PI.pos_food, v_objs)) {
                          //move(id, dirFood);
                          Info_obj IO;
                          IO.id = id;
                          IO.pos_obj = PI.pos_food;
                          IO.dist_obj = distFood;
                          IO.dir_obj = dirFood;
                          v_objs.push_back(IO);
                      }
                      else {
                          //move(id, dirEnem);
                          Info_obj IO;
                          IO.id = id;
                          IO.pos_obj = PI.pos_enem;
                          IO.dist_obj = distEnem;
                          IO.dir_obj = dirEnem;
                          v_objs.push_back(IO);
                      } 
                          
                  } else {
                      if (distFood - distEnem <= 5 and distFood - distZombie <= 5 and not repeated(PI.pos_food, v_objs)) {
                          //move(id, dirFood);
                          Info_obj IO;
                          IO.id = id;
                          IO.pos_obj = PI.pos_food;
                          IO.dist_obj = distFood;
                          IO.dir_obj = dirFood;
                          v_objs.push_back(IO);
                      }
                      else {
                          if (distZombie < distEnem and not repeated(PI.pos_zombie, v_objs)) {
                              //move(id, dirZombie);
                              Info_obj IO;
                              IO.id = id;
                              IO.pos_obj = PI.pos_zombie;
                              IO.dist_obj = distZombie;
                              IO.dir_obj = dirZombie;
                              v_objs.push_back(IO);
                          }
                           else {
                              //move(id, dirEnem);
                              Info_obj IO;
                              IO.id = id;
                              IO.pos_obj = PI.pos_enem;
                              IO.dist_obj = distEnem;
                              IO.dir_obj = dirEnem;
                              v_objs.push_back(IO);
                          } 
                      }
                  }
              }
          }
          
      }
      
      int n = v_objs.size();
      for (int i = 0; i < n; ++i) {
          move(v_objs[i].id, v_objs[i].dir_obj);
      }
  }
};

//Do not modify the following line.
RegisterPlayer(PLAYER_NAME);
