module ShiftRegister(
    input wire clk,
    input wire reset,
    input wire shift_in,
    input wire enable, 
    outwire [7:0] shift_out
);

    reg [7:0] register;
    always @(posedge clk or posedge reset) begin
        if(reset)
            register <= 8'b00000000;
        else if (enable)
            register <= {shift_in, register[7:1]};
        end

        assign shift_out = register;

endmodule;