// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington CoMotion, email: license@uw.edu.

/// @file   core/kinematics/inverse/jump.hh
/// @brief  Utility functions for calculating jumps by knowing desired atom positions
/// @author Jack Maguire


#ifndef INCLUDED_core_kinematics_inverse_jump_HH
#define INCLUDED_core_kinematics_inverse_jump_HH


// Package headers
#include <core/kinematics/inverse/AlignmentAtom.fwd.hh>
#include <core/id/types.hh>

#include <core/types.hh>

#include <core/id/AtomID.hh>
#include <core/kinematics/Stub.hh>
#include <core/kinematics/Jump.fwd.hh>
#include <core/conformation/Conformation.hh>

#include <numeric/xyzVector.hh>

#include <array>

namespace core {
namespace kinematics {
namespace inverse {

///////////////////////
// This is the big one!
///@brief Update a desired jump in the conformation to place the atoms in the AlignmentAtomArray to the desired position
///@details protocol is described as comments in the body of the code.
///@author Jack Maguire
Jump
calculate_new_jump(
	conformation::Conformation const & conformation,
	core::Size const jump_id,
	AlignmentAtomArray const & atoms
);

} // namespace inverse
} // namespace kinematics
} // namespace core


#endif // INCLUDED_core_kinematics_inverse_jump_HH
