# Logging Framework

## Requirement analysis

1. Supporting multiple log level: DEBUG, INFO, ERROR, FATAL etc
2. Different log outputs: console, file, network, db
3. Logs should include timestamps and log level in the output for debugging.
4. Thread safe logging (multiple threads can log simulatenously).
5. Asynchrononus logging support (message queue based) - keeps flushing in the background
6. Formatter system (plain text, custom, readme, json)
7. Batch processing via buffering for reducing the IO overhead.
8. Log context (thread id, request id etc)
9. Errors in the logging system must not crash the main application. 
10. Centralised log manager handles the logger lifecycle and configs.

## Key metrics
1. Performance: Asynchronous mode should not block threads.
2. Reliability: Logs must not be lost (flushing and retry mechanism).
3. Scalability: Add new sources easily.
4. Thread safety: Concurrent load/write requests.

## SOLID principles

1. S - SRP (single responsibily : eg: buffering, writing)
2. O - OCP (New appenders can be added without modifying the logger base class)
3. L - LSP (All appenders have same interface)
4. I - ISP (Writters and the formatters are separatered by interfaces)
5. D - DIP (Logger interacts via abstractions not conrete classes)

## Design Patterns used

1. Singleton - Global logger instance
2. Observer - Listeners for log events (dashboard, metrics)
3. Strategy - Formatting strategies (json, plain)
4. Factory - Different appenders
5. Decorator - Add timestamps for the log

## Classes

1. Logger (Singleton)
    - void log(LogLevel level, string message)
    - list<appender*> targets
    - handle the async and syn flushing logic

2. LogMessage
    - Members
        - timestamp, log level, message, source file, thread id

3. LogAppender (Interface)
    - void append(LogMessage)

Subclasses: ConsoleAppender, FileAppender, RemoteAppender

4. BufferedAppender (Decorator)
    - vector<LogMessage>
    - buffer(LogMessage)
    - flush(buffer)

5. AsyncLoggerWorker
    - queue<LogMessages>
    - background thread pool
    - append()

6. LogFormatter
    - format(LogMessage)

Subclasses: PlainTextFormatter, JSONFormatter

## System flow

1. Logger created - level, appenders, format
2. Log Call - log(INFO, "msg") - Log message
3. Asyn - message will be queued
    Sync - directly passed to the appender
4. Formatting - LogFormatter
5. Buffering - Batch written on the flush trigger
6. Shutdown - Log is flushed

## Future scope
1. Analytics (data is unstructured/ structured)
2. Elastic search (ditributed log analytics system)
3. Log stream subscriptions (websockets)
