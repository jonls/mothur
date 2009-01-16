#ifndef NOCOMMAND_H
#define NOCOMMAND_H
/*
 *  nocommand.h
 *  Dotur
 *
 *  Created by Sarah Westcott on 1/2/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

/* This command is run if the user enters an invalid command. */

#include <Carbon/Carbon.h>
#include "command.hpp"

class NoCommand : public Command {

public:
	NoCommand();
	~NoCommand();
	int execute();
	
private:
		
};

#endif