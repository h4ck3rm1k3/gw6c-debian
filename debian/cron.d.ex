#
# Regular cron jobs for the gw6c package
#
0 4	* * *	root	[ -x /usr/bin/gw6c_maintenance ] && /usr/bin/gw6c_maintenance
