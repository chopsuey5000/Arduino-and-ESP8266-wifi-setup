ssid = ""
pass = ""
count = 0

uart.setup(0,9600,8,0,1)

print ("UART.setup(0,9600,8,0,1) finished")

function set_wifi(s,p)
    ssid = s
    pass = p
    connect_wifi()
end

function connect_wifi()
  count = count + 1
  wifi.setmode(wifi.STATION)
  wifi.sta.config(ssid,pass)
  wifi_ip = wifi.sta.getip()
  if wifi_ip == nil and count < 20 then
    tmr.alarm(0, 1000,0,connect_wifi)
  elseif count >= 20 then
    wifi_connected = false
    print("Wifi connect timed out.")
  else
    wifi_connected = true
    print("count"..count)
    tmr.delay(2500000)
    print("Got IP "..wifi_ip.."\n")
    tmr.delay(2500000)
    print("MAC address "..wifi.sta.getmac())
    --dofile("nextstep.lua")
  end
end