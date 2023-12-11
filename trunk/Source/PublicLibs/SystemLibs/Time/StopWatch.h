/* StopWatch.h
 * 
 *  Author          : Alexander J. Yee
 *  Date Created    : 02/12/2015
 *  Last Modified   : 11/05/2023
 * 
 *      A stopwatch that tracks both wall time and CPU time. This is used for
 *  generating CPU utilization and efficiency profiles.
 * 
 *  Like any other stopwatch, it can be stopped and resumed so that you time
 *  only stuff that you care about it.
 * 
 */

#pragma once
#ifndef ymp_StopWatch_H
#define ymp_StopWatch_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/BasicLibs/ConfigTree/ConfigObject.h"
#include "Time.h"
namespace ymp{
namespace Time{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class StopWatch{
    PerformanceTimeStamp m_last;
    PerformanceTimeDuration m_total;
    bool m_is_running;

public:
    StopWatch(){ reset(); }

    void reset();
    void start();
    void stop();

public:
    double get_wall_time() const;
    PerformanceTimeDuration get_current() const;

    void print() const;
    std::string to_string() const;

public:
    //  Serialization
    void Serialize(std::string& stream) const;
    void Deserialize(const char*& stream);

    void load_config(const ConfigObject& config);
    ConfigObject now_to_config() const;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
