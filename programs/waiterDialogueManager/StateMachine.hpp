// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include <yarp/os/BufferedPort.h>
#include <yarp/os/Port.h>
#include <yarp/os/RpcClient.h>
#include <yarp/os/Time.h>

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/CartesianControl.h>
#include <yarp/dev/ControlBoardInterfaces.h>

#define VOCAB_FOLLOW_ME VOCAB4('f','o','l','l')
#define VOCAB_STOP_FOLLOWING VOCAB4('s','f','o','l')


namespace teo
{

/**
 * @ingroup waiterDialogueManager
 *
 * @brief implements a specific state machine for waiterDialogueManager.
 */
class StateMachine : public yarp::os::Thread {
protected:

    yarp::os::BufferedPort<yarp::os::Bottle> *inSrPort;
    yarp::os::Port *outCmdPort;
    yarp::os::Port *outTtsPort;

    int _machineState;

    yarp::os::ConstString _inStrState1;

    void ttsSay(const yarp::os::ConstString& sayConstString);
    yarp::os::ConstString asrListen();

public:

    /**
     * Initialization method. The thread executes this function
     * when it starts and before "run". This is a good place to 
     * perform initialization tasks that need to be done by the 
     * thread itself (device drivers initialization, memory 
     * allocation etc). If the function returns false the thread 
     * quits and never calls "run". The return value of threadInit()
     * is notified to the class and passed as a parameter 
     * to afterStart(). Note that afterStart() is called by the 
     * same thread that is executing the "start" method.
     */
    bool threadInit();

    /**
     * Loop function. This is the thread itself.
     */
    void run();

    /**
     * Get its state.
     */
    int getMachineState();

    /** Register an input callback port for asr. */
    void setInSrPort(yarp::os::BufferedPort<yarp::os::Bottle>* inSrPort);

    /** Register an output Port for commands. */
    void setOutCmdPort(yarp::os::Port* outCmdPort);

    /** Register an output Port for tts. */
    void setOutTtsPort(yarp::os::Port* outTtsPort);

};

}  // namespace teo

#endif

