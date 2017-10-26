/**
\file
\brief Header file that contains default constant values

This file contains constant values that are used in program
*/

#pragma once


const double EPSILON = 0.00001;
const int MAX_ITERATIONS = 50000;
const int COUNT_SUCCESSES = 100;
const double STEP = 0.01;

const string ROSENBROCK_FUNCTION = "100 * (x(1) - x(0) * x(0))*(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0)) (Non-convex)";
const string HIMMELBLAU_FUNCTION = "((x(0)*x(0) + x(1) - 11)*(x(0)*x(0) + x(1) - 11) + (x(0) + x(1)*x(1) - 7)*(x(0) + x(1)*x(1) - 7)) (Non-convex)";
const string FOURTH_DEGREE_FUNCTION = "(x(0)*x(0)*x(0)*x(0) + x(1)*x(1)*x(1)*x(1)) (Convex)";
