# Logging Framework

## Requirement

1. Support different logging levels (eg: WARN, ERROR, FATAL, INFO, DEBUG).
2. Each log message will have additional information (timestamp, thread id etc).
3. Buffered write to the logs to reduce the I/O overhead.
4. Log formatting strategies (JSON, plain text etc).
5. Thread safe and supports concurrent writes
6. Logging framework should be independent and fault should not fail or affect other functionalites.
7. Appender: Different output will be supported (File, Remote server, console).
8. Optional: Switch off a particular log level or divert the particular log level to a different output.
9. Asynchronouhs logging: Thread pool, log queue
10. System health Monitoring service: Monitoring logs, dashboard(UI)

## Key metrics

1. Latency: Async logging for reducing latency during flush()
2. Reliability: No loss of critical logs
3. Scalability: We can scale the input or output of the logging framework. Adding more log levels
4. Extensibility: Adding new logging level should be easy

## Design Patterns

1. Singleton - Global logger instance
2. Observer - Listeners for log events (dashboard)
3. Factory - Different types of appenders 
4. Decorator - Appender (buffer), additional log information
5. Strategy - Different formatting strategies (plain, JSON etc)

## SOLID principles

1. S - SRP: Every class has single responsibility
2. O - OCP: Strategy, factory
3. L - LSP: Appender, formatter
4. I - ISP: Loose coupling (input, appender)
5. D - Appender (concrete class, source)

## Classes

1. AsynchLoggerWorker 
    - data members
        - queue<LogMessage>
        - vector<Thread*>
        - unordered_map<Thread, >
    - methods 
        - assignTaskToThread()
        - 

<!-- 
class LoggingFramework {
    private:
        static LoggingFramework* instance;
        LoggingFramework()
        {
            LoggingFramework* instance = new LoggingFramework();
        }
    public:
       static LoggingFramework* getInstance()
        {   
            <!-- if(instance == NULL)
            {
               instance = new LoggingFramework();
            } -->
            return instace;
        }
};
LoggingFramework::instance = new LoggingFramework(); -->