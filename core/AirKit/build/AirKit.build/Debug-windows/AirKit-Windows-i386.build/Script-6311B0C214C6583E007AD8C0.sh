#!/bin/sh
rm -f "${SRCROOT}/en.lproj/Localizable.strings"
# Then append the one from the code
genstrings -a -q -o "${SRCROOT}/en.lproj" "${SRCROOT}"/*m "${SRCROOT}"/NSColor.subproj/*m "${SRCROOT}"/NSColorPicker.subproj/*m "${SRCROOT}"/NSDrawer.subproj/*m ""${SRCROOT}"/NSEvent.subproj/*m ${SRCROOT}"/NSMenu.subproj/*m "${SRCROOT}"/NSTextView.subproj/*m "${SRCROOT}"/NSToolbar.subproj/*m "${SRCROOT}"/RTF.subproj/*m "${SRCROOT}"/Win32.subproj/*m
