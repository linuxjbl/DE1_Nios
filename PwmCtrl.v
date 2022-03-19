module PwmCtrl (
	RST_N,
	CLK,
	LED0
 ); 


input		CLK, RST_N;
output		LED0;
reg [27:0]	counter0;
wire 		counter0_clr, counter0_dec;

always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter0 <= 0;
	end else begin
		if(counter0_clr == 1'b1) begin
			counter0 <= 0;
		end else begin
			counter0 <= counter0 + 1;
		end
	end
end

assign counter0_clr = (counter0 >= 49999999) ? 1'b1 : 1'b0;
assign counter0_dec = (counter0 < 25000000) ? 1'b1 : 1'b0;
assign LED0 = counter0_dec;

endmodule
