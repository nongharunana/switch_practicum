package practicum;

import org.usb4java.Device;

public class McuWithPeriBoard extends McuBoard
{
	private static final byte RQ_GET_SWITCH_1   = 1;
    private static final byte RQ_GET_SWITCH_2	= 2;
    private static final byte RQ_GET_SWITCH_3   = 3;
    private static final byte RQ_GET_SWITCH_4   = 4;
    private static final byte RQ_GET_SWITCH_5   = 5;
    public McuWithPeriBoard(Device device) {
		super(device);
	}

    /**
     * Check the state of the switch
     * 
     * @return true when the switch is pressed; false otherwise
     */
    public boolean getSwitch_1()
    {
        byte[] ret = this.read(RQ_GET_SWITCH_1, (short) 0, (short) 0);
        System.out.format("%s from switch 1\n",ret[0]);
        return ret[0] == 1;
    }
    public boolean getSwitch_2()
    {
        byte[] ret = this.read(RQ_GET_SWITCH_2, (short) 0, (short) 0);
        System.out.format("%s from switch 2\n",ret[0]);
        return ret[0] == 2;
    }
    public boolean getSwitch_3()
    {
        byte[] ret = this.read(RQ_GET_SWITCH_3, (short) 0, (short) 0);
        System.out.format("%s from switch 3\n",ret[0]);
        return ret[0] == 3;
    }
    public boolean getSwitch_4()
    {
        byte[] ret = this.read(RQ_GET_SWITCH_4, (short) 0, (short) 0);
        System.out.format("%s from switch 4\n",ret[0]);
        return ret[0] == 4;
    }
    public boolean getSwitch_5()
    {
        byte[] ret = this.read(RQ_GET_SWITCH_5, (short) 0, (short) 0);
        System.out.format("%s from switch 5\n",ret[0]);
        return ret[0] == 5;
    }
}
