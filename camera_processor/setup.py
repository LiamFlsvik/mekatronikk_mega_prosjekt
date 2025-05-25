from setuptools import find_packages, setup
import os
import sys
package_name = 'camera_processor'
if 'VIRTUAL_ENV' in os.environ:
    sys.executable = os.path.join(os.environ['VIRTUAL_ENV'], 'bin', 'python')

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lhf',
    maintainer_email='liam.folsviks@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    entry_points={
        'console_scripts': [
    'red_cube_detector = camera_processor.red_cube_detector:main',
    'cube_tracker = camera_processor.cube_tracker:main',
],
    },
)
