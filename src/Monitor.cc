#include "Monitor.h"

std::vector<Monitor> Monitor::monitors() {
    int numberOfMonitors;
    GLFWmonitor** monitorRefs = glfwGetMonitors(&numberOfMonitors);
    std::vector<Monitor> monitors;
    for( int i=0; i<numberOfMonitors; i++ ) {
        monitors.push_back({monitorRefs[i]});
    }
    return monitors;
}

Monitor Monitor::primaryMonitor() {
    return {glfwGetPrimaryMonitor()};
}

Position Monitor::position() {
    int width, height;
    glfwGetMonitorPos(monitor, &width, &height);
    return {width, height};
}

Size Monitor::physicalSize() {
    int widthMM, heightMM;
    glfwGetMonitorPhysicalSize(monitor, &widthMM, &heightMM);
    return {widthMM, heightMM};
}

ContentScale Monitor::contentScale() {
    float xscale, yscale;
    glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    return {xscale, yscale};
}

String Monitor::name() {
    return glfwGetMonitorName(monitor);
}