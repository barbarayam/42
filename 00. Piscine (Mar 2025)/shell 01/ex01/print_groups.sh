#!/bin/bash
# display the id of the user, but only those usergroups, replace separation with comma, remove the newline
id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
