#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "io.h"

/**
 * @file
 * @author István Bozsó <bozso.istvan@csfk.mta.hu>
 * @version 0.1
 *
 */

#if 0

typedef struct Stream {
    struct IErrorHandler eh;
    FILE* stream;
} Stream;

typedef struct StreamFactory {
    struct IErrorHandler const eh;
} StreamFactory;

StreamFactory io_new_stream_factory(IErrorHandler const eh)
{
    return (struct StreamFactory) {
        .eh = eh,
    };
}

/**
 * Creates a new Stream struct from a FILE* stream.
 * 
 * @param self the factory struct 
 * @param stream FILE stream to be used 
 * @return a new Stream
 */
Stream io_new_stream(StreamFactory const self, FILE*const stream)
{
    return (struct Stream){
        .stream = stream,
        .eh = self.eh,
    };
}

/**
 * Opens a file from path and sets up the Stream struct.
 * 
 * @param path Path to the file to be opened.
 * @param[out] file to be opened.
 * @return Status of the operation.
 * 
 */
Status io_stream_from_path(StreamFactory const self,
                           const_str path, const_str mode,
                           Stream *stream)
{
    FILE* file = fopen(path, mode);
    
    if (file != NULL) {
        return PError;
    }
    
    *stream = io_new_stream(self, file);
    
    return Ok;
}
#endif
