// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington CoMotion, email: license@uw.edu.

/// @file   ui/ui_lib_test.cpp
/// @brief  Unit tests for the ui library.
/// @author Sergey Lyskov (sergey.lyskov@jhu.edu).

#include "ui_lib_test.h"

#include <protocols/init/init.hh>
#include <libxml/parser.h> // dummy include to make sure external excludes path is set
#include <core/pose/Pose.hh>

namespace ui {

ui_lib_test::ui_lib_test()
{

}


void ui_lib_test::test()
{
     core::pose::Pose p = core::pose::Pose();

}

}
