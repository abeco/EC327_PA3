#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

/*#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
*/
#include "Model.h"

using namespace std; //do i need this? I don't think so

void do_sail_command(Model* model);
void do_go_command(Model* model);
void do_run_command(Model* model);
void do_port_command(Model* model);
void do_hide_command(Model* model);
void do_anchor_command(Model* model);
void do_list_command(Model* model);
void do_dock_command(Model* model);

#endif