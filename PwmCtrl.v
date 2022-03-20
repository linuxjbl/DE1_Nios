module PwmCtrl (
	RST_N,
	CLK,
	LED,
	HEX0,
	HEX1,
	PUSH
 ); 

input		CLK, RST_N;
output		[9:0] LED;
output		[6:0] HEX0;
output		[6:0] HEX1;
input		[3:0] PUSH;

reg [27:0]	counter0;
wire 		counter0_clr, counter0_dec;
wire [27:0] Decode0;
wire [27:0] Period0;


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

assign counter0_clr = (counter0 >= Period0-1) ? 1'b1 : 1'b0;
assign counter0_dec = (counter0 < Decode0) ? 1'b1 : 1'b0;
//assign LED0 = counter0_dec;
assign LED[0] = counter0_dec;
assign LED[1] = ~counter0_dec;
assign LED[2] = counter0[27];
assign LED[3] = counter0[26];
assign LED[4] = counter0[25];
assign LED[5] = counter0[24];
assign LED[6] = ~counter0[27];
assign LED[7] = ~counter0[26];
assign LED[8] = ~counter0[25];
assign LED[9] = ~counter0[24];


    nios2e u0 (
        .clk_clk                            (CLK),  
        .reset_reset_n                      (RST_N),  
        .period0_external_connection_export (Period0), 
        .decode0_external_connection_export (Decode0),
        .hex0_external_connection_export    
				({HEX1[0], HEX0[6:0]}), 
        .push_external_connection_export    (PUSH[1:0]) 
 
    );

endmodule
