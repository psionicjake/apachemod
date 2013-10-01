#include <stdio.h>
#include "apr_hash.h"
#include "ap_config.h"
#include "ap_provider.h"
#include "httpd.h"
#include "http_core.h"
#include "http_config.h"
#include "http_log.h"
#include "http_protocol.h"
#include "http_request.h"
#include <unistd.h>

module AP_MODULE_DECLARE_DATA selfdestruct_module =
{
    STANDARD20_MODULE_STUFF,
    NULL,               /* Per-directory configuration handler */
    NULL,               /* Merge handler for per-directory configurations */
    NULL,               /* Per-server configuration handler */
    NULL,               /* Merge handler for per-server configurations */
    example_directives, /* Any directives we may have for httpd */
    register_hooks      /* Our hook registering function */
};

static void register_hooks(apr_pool_t *pool)
{
    /* Create a hook in the request handler, so we get called when a request arrives */
    ap_hook_handler(selfdestruct_handler, NULL, NULL, APR_HOOK_LAST);
}

static int selfdestruct_handler(request_rec *r)
{
    /* First off, we need to check if this is a call for the "example-handler" handler.
 *      * If it is, we accept it and do our things, if not, we simply return DECLINED,
 *           * and the server will try somewhere else.
 *                */
    if (!r->handler || strcmp(r->handler, "selfdestruct-handler")) return (DECLINED);

    /* Now that we are handling this request, we'll write out "Hello, world!" to the client.
 *      * To do so, we must first set the appropriate content type, followed by our output.
 *           */
int main()
{
	    sleep(10);
            ap_set_content_type(r, "text/html");
            ap_rprintf(r, "Hello, world!");
        }
    }
}
    /* Lastly, we must tell the server that we took care of this request and everything went fine.
 *      * We do so by simply returning the value OK to the server.
 *           */
    return OK;
}
