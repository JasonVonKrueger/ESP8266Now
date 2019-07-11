(function process(/*RESTAPIRequest*/ request, /*RESTAPIResponse*/ response) {

	var gr = new GlideRecord('incident');
	gr.initialize();
	
	gr.caller_id = 'b483df9cdbe0330040dc9006db96190d';
	gr.short_description = 'Button was pushed.';
	
	gr.insert();

})(request, response);
