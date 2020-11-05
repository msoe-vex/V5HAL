#include "LeftDriveSensorNode.h"

LeftDriveSensorNode::LeftDriveSensorNode() {
    _handle = new ros::NodeHandle();
    _encoder_pos = new std_msgs::Int16();
    _encoder_vel = new std_msgs::Int16();
}

void LeftDriveSensorNode::setup() {
    // Define a topic we will publish to, and where the value
    // will be stored
    ros::Publisher pos_msg("LeftDriveSensorPos", _encoder_pos);

    // Define a topic we will publish to, and where the value
    // will be stored
    ros::Publisher vel_msg("LeftDriveSensorVel", _encoder_vel);

    // Initialize the handler, and set up data relating to what this node publishes
    _handle->initNode();
    _handle->advertise(pos_msg);
    _handle->advertise(vel_msg);

    // Add the corresponding publishers to the memory locations that hold their data
    addMessageHolder(&pos_msg, _encoder_pos);
    addMessageHolder(&vel_msg, _encoder_vel);
}

void LeftDriveSensorNode::publish() {
    // Put our value(s) into memory where the publisher is told to look
    _encoder_pos->data = 0;
    _encoder_vel->data = 0;

    // Run the publisher loop (does not handle delay)
    V5Publisher::publish(*_handle);
} 

LeftDriveSensorNode::~LeftDriveSensorNode() {
    delete _handle;
    delete _encoder_pos;
    delete _encoder_vel;
}