#!/bin/bash
ln -s tempfile.txt softlink
ln tempfile.txt hardlink_name
mkfifo myfifo
