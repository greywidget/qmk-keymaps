USER = greywidget

iris:
	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/iris qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	cd qmk_firmware
	# make build_dir=$(shell pwd)/build -j 1 -C qmk_firmware keebio/iris/rev2:greywidget
	qmk compile -kb keebio/iris/rev2 -km $(USER)
	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	cd ..

.PHONY: iris
