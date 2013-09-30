#include "stdio.h"

module AP_MODULE_DECLARE_DATA selfdestruct_module =
{
    STANDARD20_MODULE_STUFF,
    create_dir_conf, /* Per-directory configuration handler */
    merge_dir_conf,  /* Merge handler for per-directory configurations */
    create_svr_conf, /* Per-server configuration handler */
    merge_svr_conf,  /* Merge handler for per-server configurations */
    directives,      /* Any directives we may have for httpd */
    register_hooks   /* Our hook registering function */
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
     i=10;
     while (--i) {
        if(i == 0) {
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
